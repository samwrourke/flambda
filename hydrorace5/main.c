#include <assert.h>
#include <fcntl.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include "bcm_host.h"
#include "GLES/gl.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"

#include "graphicstoolkit_conv.c"
#include "matrixtools.c"

#include "newmeshesheader.c"
#include "iconmeshheader.c"
#include "uimeshes.c"
#include "titleheader.c"
#include "backmeshes.c"
#include "scenemeshes.c"
#include "numberheader.c"
#include "gameengine.c"

#include "testgameheader2.c"
#include "canyonheader.c"

#define NUMGAMES 2
struct Game *games[NUMGAMES] = {&testgame,&canyongame};
//struct Game * (*games[1])(void) = {*testgamefunc};

#include "charcodes.c"

#define MOUSEFILE "/dev/input/mice"
#define KYBRDFILE "/dev/input/event1"

#define OBSEVERPOS 0.0f,6.0f,-20.0f
#define MINMAPPOS 2000.0f,4000.0f,1000.0f
#define SPEEDOPOS -40.0f,20.0f,-80.0f
#define WONPOS 0.0,0.0,40.0

double fov = 45.0;

struct State {
	uint32_t screen_width;
	uint32_t screen_height;
	DISPMANX_DISPLAY_HANDLE_T dispman_display;
	DISPMANX_ELEMENT_HANDLE_T dispman_element;
	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;
	EGLConfig config;
	EGL_DISPMANX_WINDOW_T nativewindow;
	VC_RECT_T dst_rect;
	VC_RECT_T src_rect;
};

void initatscale(struct State *state,int scale) {
	DISPMANX_UPDATE_HANDLE_T dispman_update = vc_dispmanx_update_start(0);;
	
	int scalewidth = state->screen_width / scale;
	int scaleheight = state->screen_height / scale;
	(state->src_rect).width = scalewidth << 16;
	(state->src_rect).height = scaleheight << 16;

	state->dispman_element = vc_dispmanx_element_add(dispman_update,state->dispman_display,0,&(state->dst_rect),0,&(state->src_rect),DISPMANX_PROTECTION_NONE,0,0,0);
	(state->nativewindow).element = state->dispman_element;
	(state->nativewindow).width = scalewidth;
	(state->nativewindow).height = scalewidth;
	vc_dispmanx_update_submit_sync(dispman_update);
	
	state->surface = eglCreateWindowSurface(state->display,state->config,&(state->nativewindow),NULL);
	eglMakeCurrent(state->display,state->surface,state->surface,state->context);	// connect the context to the surface
	
	glViewport(0,0,(GLsizei) scalewidth,(GLsizei) scaleheight);	// glViewport with appropriate sizes
}

void initatscale_and_partialdestroy(struct State *state,int scale) {
	EGLSurface oldsurf = state->surface;
	
	initatscale(state,scale);
	
	eglSwapBuffers(state->display,state->surface);	
	eglDestroySurface(state->display,oldsurf);
}

void initegl(struct State *state) {
	uint32_t success = 0;
	EGLBoolean result;
	EGLint num_config;
		
	static const EGLint attribute_list[] = {EGL_RED_SIZE,8,EGL_GREEN_SIZE,8,EGL_BLUE_SIZE,8,EGL_ALPHA_SIZE,8,EGL_SURFACE_TYPE,EGL_WINDOW_BIT,EGL_DEPTH_SIZE,8,EGL_NONE};

	state->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);	// get an EGL display connection
	assert(state->display != EGL_NO_DISPLAY);

	result = eglInitialize(state->display,NULL,NULL);	// initialize the EGL display connection
	assert(result != EGL_FALSE);
	
	result = eglChooseConfig(state->display,attribute_list,&(state->config),1,&num_config);	// get an appropriate EGL frame buffer configuration
	assert(result != EGL_FALSE);
	
	state->context = eglCreateContext(state->display,state->config,EGL_NO_CONTEXT,NULL);	// create an EGL rendering context
	assert(state->context != EGL_NO_CONTEXT);

	success = graphics_get_display_size(0,&state->screen_width,&state->screen_height);	// create an EGL window surface
	assert(success >= 0);
	
	(state->dst_rect).x = 0;
	(state->dst_rect).y = 0;
	(state->dst_rect).width = state->screen_width;
	(state->dst_rect).height = state->screen_height;
	
	(state->src_rect).x = 0;
	(state->src_rect).y = 0;
	
	state->dispman_display = vc_dispmanx_display_open(0);
	
	initatscale(state,1);
}

void initogles(struct State *state) {
	// Set nice enables
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	glEnable(GL_BLEND);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LINE_SMOOTH);

	// Depth testing

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	
	// Enable these to use glVertexPointer, glColorPointer

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
		
	// Set appropriate matrix values
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float nearp = 1.0f;
	float farp = 100000.0f;
	float hht = nearp * (float) tan(fov / 2.0 / 180.0 * M_PI);
	float hwd = hht * (float) state->screen_width / (float) state->screen_height;
	glFrustumf(-hwd,hwd,-hht,hht,nearp,farp);
	
	GLfloat matrix[16] = scalematrix_m(1.0f,1.0f,-1.0f,1.0f);
	glMultMatrixf(matrix);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void clearup(struct State *state) {
	DISPMANX_UPDATE_HANDLE_T dispman_update;
	int s;

	glClear(GL_COLOR_BUFFER_BIT);
	eglSwapBuffers(state->display,state->surface);
	
	eglDestroySurface(state->display,state->surface);
	
	dispman_update = vc_dispmanx_update_start(0);
	s = vc_dispmanx_element_remove(dispman_update,state->dispman_element);
	assert(s == 0);
	vc_dispmanx_update_submit_sync(dispman_update);
	s = vc_dispmanx_display_close(state->dispman_display);
	assert(s == 0);
	
	eglMakeCurrent(state->display,EGL_NO_SURFACE,EGL_NO_SURFACE,EGL_NO_CONTEXT);
   	eglDestroyContext(state->display,state->context);
   	eglTerminate(state->display);
}
/*
void getmouseinput(int fd,char *buttons,int *mousex,int *mousey) {
	signed char mousedata[3];
	read(fd,mousedata,sizeof mousedata);
	memcpy(buttons,mousedata,1);
	(*mousex) += mousedata[1];
	(*mousey) += mousedata[2];
}
*/

//int rungame(struct State *screenstate,struct Game * (*gamefunc)(void)) {
int rungame(struct State *screenstate,struct Game *game) {
	//struct Game *game = (*gamefunc)();
	// Reset the game
	
	(*(game->resetfunction))();
	glClearColor(game->backr,game->backg,game->backb,game->backa);
	
	// Set up game objects
	//(*(game->setupfunction))();
	// Set up stuff needed to run
	
	char quitflag = 1;
	int returnvalue;
	char readflag = 0;
	//int mx = 0;
	//int my = 0;
	//char buttons;
	
	//int currentscale = 1;
	//int newscale;
	
	signed char upkey = 0;
	signed char downkey = 0;
	signed char leftkey = 0;
	signed char rightkey = 0;
	
	signed char won = 0;
	int rank = 0;
	struct Mesh *wonmesh;// = &losemesh;
	
	#pragma omp parallel
	{
		#pragma omp master
		{
			int i;
			while (quitflag) {
				// Main game loop
				
				glClear(GL_COLOR_BUFFER_BIT);
				loadobsevermatrix(game->player,OBSEVERPOS);
				drawmesh_nomat(game->backmesh);
				drawmesh_nomat(game->scenemesh);
				
				if (won) {
					aiplane(game->player,game->walls,game->lines,game->numaiplayers,game->aiplayers,&(game->finishline));
				}
				else {
					updateplane(game->player,upkey - downkey,leftkey - rightkey,game->walls,game->numaiplayers,game->aiplayers,&(game->finishline));
					if ((game->player)->laps > game->laps) {
						won = 1;
						for (i = 0; i < game->numaiplayers; i++) {
							rank += ((game->aiplayers) + i)->laps > game->laps;
						}

						switch (rank) {
							case 0:
								wonmesh = &onemesh;
								break;
							case 1:
								wonmesh = &twomesh;
								break;
							case 2:
								wonmesh = &threemesh;
								break;
							default:
								wonmesh = &losemesh;
						};
					}
				}
				drawplane(game->player);
				
				for (i = 0; i < game->numaiplayers; i++) {
					aiplane((game->aiplayers) + i,game->walls,game->lines,game->numaiplayers,game->aiplayers,&(game->finishline));
					drawplane((game->aiplayers) + i);
				}
				
				// Mini map
				glClear(GL_DEPTH_BUFFER_BIT);
				loadminmapmatrix(game->player,MINMAPPOS);
				drawmesh_nomat(game->backmesh);				
				for (i = 0; i <= game->numaiplayers; i++) {
					drawicon((game->aiplayers) + i);
				}
				
				// Speedometer
				displayspeed(game->player,SPEEDOPOS);
				
				if (won) {
					glLoadIdentity();
					glTranslatef(WONPOS);
					//glRotatef(180.0f,0.0f,1.0f,0.0f);
					drawmesh(wonmesh);
					//drawmesh_nomat(wonmesh);
				}
				
				eglSwapBuffers(screenstate->display,screenstate->surface);
				
				// Rescale screen if we need to
				
				//newscale = scalelevel(&player);
				/*
				newscale = scalelevel(player);
				if (newscale != currentscale) {
					currentscale = newscale;
					initatscale_and_partialdestroy(&screenstate,currentscale);
				}*/
								
				// Handle events
				if (readflag) {
					readflag = 0;
					printf("Saving\n");
				
					FILE *screenbufstoredfile = fopen("screenout.data","wb");
					if (screenbufstoredfile == NULL) {
						printf("Failed to open file\n");
					}
					else {
						void *screendata = malloc(screenstate->screen_width * screenstate->screen_height * 4);
						glReadPixels(0,0,screenstate->screen_width,screenstate->screen_height,GL_RGBA,GL_UNSIGNED_BYTE,screendata);
						fwrite(screendata,screenstate->screen_width * screenstate->screen_height * 4,1,screenbufstoredfile);
						fclose(screenbufstoredfile);
						free(screendata);
					}
				}
			}
		}
		/*
		#pragma omp sections
		{
			#pragma omp section
			{
				int mfd = open(MOUSEFILE,O_RDONLY);
				if (mfd != -1) {
					while (quitflag) {
						getmouseinput(mfd,&buttons,&mx,&my);
					}
					close(mfd);
				}
			}
			#pragma omp section
			{
		*/
		#pragma omp single
		{
			unsigned char kybrddata[INBYTES];
			int kfd = open(KYBRDFILE,O_RDONLY);
			if (kfd != -1) {
				while (quitflag) {
					read(kfd,&kybrddata,sizeof kybrddata);
					if (kybrddata[TYPEBYTE] == NORMALTYPE) {
						// Handle keys
					 	if (kybrddata[PRESSBYTE] == KEYPRESS) {
					 		// Handle key presses
							switch (kybrddata[CODEBYTE]) {
								case QCODE:	quitflag = 0;	returnvalue = -1;	break;
								case RCODE:	quitflag = 0;	returnvalue = 0;	break;
								case XCODE:	readflag = 1;	break;
								case WCODE:	upkey = 1;	break;
								case SCODE:	downkey = 1;	break;
								case ACODE:	leftkey = 1;	break;
								case DCODE:	rightkey = 1;	break;
							}
						}
						else if (kybrddata[PRESSBYTE] == KEYRELEASE) {
							// Handle key releases
							switch (kybrddata[CODEBYTE]) {
								case WCODE:	upkey = 0;	break;
								case SCODE:	downkey = 0;	break;
								case ACODE:	leftkey = 0;	break;
								case DCODE:	rightkey = 0;	break;
							}
						}
					}
				}
				close(kfd);
			}
		}
	}
	return returnvalue;
}

int title(struct State *screenstate) {
	//glClearColor(1.0f,1.0f,1.0f,0.9f);
	glClearColor(WHITE);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,40.0f);
	drawmesh_nomat(&titlemesh);
	eglSwapBuffers(screenstate->display,screenstate->surface);
	
	char quitflag = 1;
	int gameflag;
	
	unsigned char kybrddata[INBYTES];
	int kfd = open(KYBRDFILE,O_RDONLY);
	
	if (kfd != -1) {
		while (quitflag) {
			read(kfd,&kybrddata,sizeof kybrddata);
			if (kybrddata[TYPEBYTE] == NORMALTYPE) {
				// Handle keys
			 	if (kybrddata[PRESSBYTE] == KEYPRESS) {
			 		// Handle key presses
					switch (kybrddata[CODEBYTE]) {
						case QCODE:	gameflag = -1;	quitflag = 0;	break;
						case ONECODE:	gameflag = 0;	quitflag = 0;	break;
						case TWOCODE:	gameflag = 1;	quitflag = 0;	break;
					}
				}
			}
		}		
	}
	
	//if (gameflag != -1) {
	//	rungame(screenstate,games[gameflag]);
	//}
	return gameflag;
}

int main() {
	printf("Hello\n");
	
	bcm_host_init();
	struct State screenstate;
	memset(&screenstate,0,sizeof(screenstate));
	initegl(&screenstate);
	
	initogles(&screenstate);

	setuimeshes();
	setmeshes();
	setbackmeshes();
	setscenemeshes();
	setnumbermeshes();
	settitlemeshes();
	
	//testgamefunc();
	int i;
	for (i = 0; i < NUMGAMES; i++) {
		(*(games[i]->setupfunction))();
	}
	
	struct termios term;
	tcgetattr(fileno(stdin),&term);
	
	term.c_lflag &= ~ECHO;
	tcsetattr(fileno(stdin),0,&term);
	
	//rungame(&screenstate,&testgame);
	int funcreturn;
	do {
		funcreturn = title(&screenstate);
		if (funcreturn != -1) {
			funcreturn = rungame(&screenstate,games[funcreturn]);
		}
	} while (funcreturn != -1);
	
	clearup(&screenstate);
	
	term.c_lflag |= ECHO;
	tcsetattr(fileno(stdin),0,&term);
	
	printf("Press enter/return");
	getchar();

	return 0;
}