GLfloat identity[16] = {1.f,0.f,0.f,0.f,0.f,1.f,0.f,0.f,0.f,0.f,1.f,0.f,0.f,0.f,0.f,1.f};

//double fov = 60.0;
GLfloat ztrans = 60.0f;

#define HYDROTRIANGLES 522

GLfloat hydrovertices[HYDROTRIANGLES * 3 * 3];
//GLfloat hydrocolours[HYDROTRIANGLES * 3 * 4];
//struct Mesh hydromesh = {identity,HYDROTRIANGLES * 3,hydrovertices,hydrocolours};

//GLfloat bluevertices[HYDROTRIANGLES * 3 * 3];
GLfloat bluecolours[HYDROTRIANGLES * 3 * 4];
struct Mesh bluemesh = {identity,HYDROTRIANGLES * 3,hydrovertices,bluecolours};

//GLfloat redvertices[HYDROTRIANGLES * 3 * 3];
GLfloat redcolours[HYDROTRIANGLES * 3 * 4];
struct Mesh redmesh = {identity,HYDROTRIANGLES * 3,hydrovertices,redcolours};

//GLfloat greenvertices[HYDROTRIANGLES * 3 * 3];
GLfloat greencolours[HYDROTRIANGLES * 3 * 4];
struct Mesh greenmesh = {identity,HYDROTRIANGLES * 3,hydrovertices,greencolours};

//GLfloat yellowvertices[HYDROTRIANGLES * 3 * 3];
GLfloat yellowcolours[HYDROTRIANGLES * 3 * 4];
struct Mesh yellowmesh = {identity,HYDROTRIANGLES * 3,hydrovertices,yellowcolours};

//GLfloat hydrovertices[HYDROTRIANGLES * 3 * 3];
GLfloat purplecolours[HYDROTRIANGLES * 3 * 4];
struct Mesh purplemesh = {identity,HYDROTRIANGLES * 3,hydrovertices,purplecolours};

/*
#define BACKTRIANGLES 544

GLfloat backvertices[BACKTRIANGLES * 3 * 3];
GLfloat backcolours[BACKTRIANGLES * 3 * 4];
struct Mesh backmesh = {identity,BACKTRIANGLES * 3,backvertices,backcolours};
*/
// Pallete

//#define MAINCOLOUR BLUE4
//#define DARKCOLOUR 0.0f,0.0f,0.15f,1.0f
//#define LIGHTCOLOUR CYAN3
#define DETAIL WHITE
#define DARKDETAIL GREY90
#define WINDOW BLACK

void setmeshes(void) {
	// Hydroplane

	int on = 0;
	struct Mesh *meshptr = &bluemesh;
	GLfloat i;
	#define MAINCOLOUR BLUE4
	#define DARKCOLOUR 0.0f,0.0f,0.15f,1.0f
	#define LIGHTCOLOUR CYAN3
	#include "hydroinclude.c"
	on = 0;
	meshptr = &redmesh;
	#undef MAINCOLOUR
	#undef DARKCOLOUR
	#undef LIGHTCOLOUR
	#define MAINCOLOUR RED
	#define DARKCOLOUR RED4
	#define LIGHTCOLOUR PINK
	#include "hydroinclude.c"
	on = 0;
	meshptr = &greenmesh;
	#undef MAINCOLOUR
	#undef DARKCOLOUR
	#undef LIGHTCOLOUR
	#define MAINCOLOUR GREEN
	#define DARKCOLOUR GREEN4
	#define LIGHTCOLOUR LIGHTGREEN
	#include "hydroinclude.c"
	on = 0;
	meshptr = &yellowmesh;
	#undef MAINCOLOUR
	#undef DARKCOLOUR
	#undef LIGHTCOLOUR
	#define MAINCOLOUR YELLOW2
	#define DARKCOLOUR YELLOW4
	#define LIGHTCOLOUR YELLOW
	#include "hydroinclude.c"
	on = 0;
	meshptr = &purplemesh;
	#undef MAINCOLOUR
	#undef DARKCOLOUR
	#undef LIGHTCOLOUR
	#define MAINCOLOUR DARKORCHID
	#define DARKCOLOUR DARKORCHID4
	#define LIGHTCOLOUR DARKORCHID1
	#include "hydroinclude.c"
	
	/*
	// wings (total 12 on 0)
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-1.0f,10.0f,	5.0f,-1.0f,5.0f,	2.0f,-0.5f,5.0f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-1.0f,10.0f,	2.0f,-1.0f,5.0f,	5.0f,-1.0f,5.0f,
				 DARKCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-1.0f,-2.5f,	2.0f,-0.5f,5.0f,	3.2f,-1.0f,5.0f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-1.0f,-2.5f,	3.2f,-1.0f,5.0f,	2.0f,-1.0f,5.0f,
				 DARKCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-1.0f,10.0f,	2.0f,-0.5f,5.0f,	2.0f,-1.0f,-2.5f,
				 DETAIL);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 2.0f,-0.5f,5.0f,	5.0f,-1.0f,5.0f,	3.2f,-1.0f,5.0f,
				 DETAIL);
				 
	// cockpit front (total 24 on 12)
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 0.0f,-1.0f,5.4f,	1.0f,-1.0f,5.0f,	0.0f,-0.7f,5.4f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-1.0f,5.0f,	1.0f,-0.7f,5.0f,	0.0f,-0.7f,5.4f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,5.0f,	0.0f,1.0f,3.5f,	0.0f,-0.7f,5.4f,
				 WINDOW);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,5.0f,	0.8f,1.0f,2.8f,	0.0f,1.0f,3.5f,
				 WINDOW);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,5.0f,	1.0f,-0.7f,4.8f,	0.8f,1.0f,2.8f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,4.8f,	0.8f,1.0f,2.6f,	0.8f,1.0f,2.8f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 0.0f,1.0f,3.5f,	0.8f,1.0f,2.8f,	0.0f,1.1f,1.0f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 0.8f,1.0f,2.8f,	0.8f,1.0f,1.0f,	0.0f,1.1f,1.0f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,4.8f,	1.0f,-0.7f,2.6f,	0.8f,1.0f,2.6f,
				 WINDOW);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,5.0f,	1.0f,-1.0f,5.0f,	1.0f,-0.7f,2.6f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,2.6f,	0.8f,1.0f,2.4f,	0.8f,1.0f,2.6f,
				 LIGHTCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-1.0f,5.0f,	1.0f,-1.0f,2.6f,	1.0f,-0.7f,2.6f,
				 MAINCOLOUR);
	
	// body (total 13 on 36)
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-1.0f,2.6f,	1.0f,-0.7f,-5.5f,	1.0f,-0.7f,2.6f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 1.0f,-0.7f,2.6f,	0.8f,1.0f,1.0f,	0.8f,1.0f,2.4f,
				 MAINCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   1.0f,-0.7f,2.6f,	1.0f,-0.7f,-0.6f,	0.8f,1.0f,1.0f,
					   LIGHTCOLOUR,DARKDETAIL);
	addtriangle_mono(&hydromesh,&on,
			 0.0f,1.1f,1.0f,	1.0f,-0.7f,1.0f,	-1.0f,-0.7f,1.0f,
			 DARKCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 0.0f,1.1f,1.0f,	0.8f,1.0f,1.0f,	1.0f,-0.7f,1.0f,
				 DARKCOLOUR);
	addtriangle_mono(&hydromesh,&on,
			 -1.0f,-0.7f,1.0f,	1.0f,-0.7f,1.0f,	1.0f,-0.7f,-5.5f,
			 DARKCOLOUR);
	addtriangle_mono(&hydromesh,&on,
			 -1.0f,-0.7f,1.0f,	1.0f,-0.7f,-5.5f,	-1.0f,-0.7f,-5.5f,
			 DARKCOLOUR);
			 
	// underside (total 3 on 49)
	addtriangle_mono(&hydromesh,&on,
			 0.0f,-1.0f,5.4f,	-1.0f,-1.0f,2.6f,	1.0f,-1.0f,2.6f,
			 DARKCOLOUR);
	addtriangle_mono_reflect(&hydromesh,&on,1,0,0,
				 0.0f,-1.0f,5.4f,	1.0f,-1.0f,2.6f,	1.0f,-1.0f,5.0f,
				 DARKCOLOUR);
	addtriangle_mono(&hydromesh,&on,
			 -1.0f,-1.0f,2.6f,	1.0f,-0.7f,-5.5f,	1.0f,-1.0f,2.6f,
			 DARKCOLOUR);
	addtriangle_mono(&hydromesh,&on,
			 -1.0f,-0.7f,-5.5f,	1.0f,-0.7f,-5.5f,	-1.0f,-1.0f,2.6f,
			 DARKCOLOUR);
	
	// backwing (total 32 on 52)
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   3.0f,0.0f,-7.5f,	3.0f,2.0f,-8.0f,	3.0f,0.0f,-6.5f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   3.0f,2.0f,-8.0f,	3.0f,2.0f,-7.0f,	3.0f,0.0f,-6.5f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   3.0f,0.0f,-7.5f,	2.0f,-0.2f,-7.5f,	3.0f,0.0f,-6.5f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   2.0f,-0.2,-7.5f,	2.0f,-0.2,-6.5f,	3.0f,0.0f,-6.5f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   3.0f,2.0f,-8.0f,	0.0f,2.5f,-8.0f,	3.0f,2.0f,-7.0f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono_reflect(&hydromesh,&on,1,0,0,
					   0.0f,2.5f,-8.0f,	0.0f,2.5f,-7.0f,	3.0f,2.0f,-7.0f,
					   MAINCOLOUR,DARKCOLOUR);
	addtriangle_bothsides_mono_reflect(&hydromesh,&on,1,0,0,
					   1.5f,-0.85f,-7.0f,	2.0f,-0.2f,-7.5f,	1.5f,-0.85,-6.0f,
					   MAINCOLOUR);
	addtriangle_bothsides_mono_reflect(&hydromesh,&on,1,0,0,
					   2.0f,-0.2,-7.5f,	2.0f,-0.2,-6.5f,	1.5f,-0.85,-6.0f,
					   MAINCOLOUR);

	// cylinders (total 240 on 84)
	GLfloat i;
	for (i = 0.0f; i > -6.0f; i -= 1.0f) {
		addcylinder_mono(&hydromesh,&on,
				 'y',0.4f,1.5f,8,0.0,
				 0.0f,-0.7f,i,
				 GREY60);
		adddisc_mono(&hydromesh,&on,
			     'y',0.25f,8,0.0,
			     0.0f,0.8f,i,
			     LIGHTCOLOUR);
		addring_mono(&hydromesh,&on,
			     'y',0.4f,0.25f,8,0.5,
			     0.0f,0.8f,i,
			     GREY50);
	}
	
	// engine (total 128 on 324)
	addcylinder_mono(&hydromesh,&on,
			 'z',1.0f,0.7f,16,0.0,
			 0.0f,0.2f,-7.0f,
			 GREY50);
	addcylinder_mono(&hydromesh,&on,
			 'z',1.0f,0.7f,-16,0.0,
			 0.0f,0.2f,-7.0f,
			 GREY50);
	addcylinder_mono(&hydromesh,&on,
			 'z',0.1f,8.0f,8,0.0,
			 0.0f,-0.3f,-6.3f,
			 GREY40);
	adddisc_mono(&hydromesh,&on,
		     'z',0.6f,16,0.0,
		     0.0f,0.2f,-6.3f,
		     GREY40);
	adddisc_mono(&hydromesh,&on,
		     'z',0.6f,-16,0.0,
		     0.0f,0.2f,-6.3f,
		     GREY40);
	addcylinder_mono(&hydromesh,&on,
			 'z',0.1f,1.5f,8,0.0,
			 0.0f,0.2f,-6.3f,
			 GREY70);	
	
	// structure (total 68 on 452)
	addcylinder_mono(&hydromesh,&on,
			 'x',0.1f,4.0f,8,0.0,
			 -2.0f,-0.85f,3.1f,
			 GREY60);
	addcylinder_mono(&hydromesh,&on,
			 'x',0.1f,4.0f,8,0.0,
			 -2.0f,-0.85f,2.8f,
			 GREY60);
	addcylinder_mono(&hydromesh,&on,
			 'z',0.08f,9.8f,8,0.0,
			 1.5f,-0.85f,-7.0f,
			 GREY60);
	addcylinder_mono(&hydromesh,&on,
			 'z',0.08f,9.8f,8,0.0,
			 -1.5f,-0.85f,-7.0f,
			 GREY60);
	addtriangle_diffsides_mono(&hydromesh,&on,
				   1.5f,-0.85f,-7.0f,	-1.5f,-0.85f,-7.0f,	1.5f,-0.85f,-6.0f,
				   MAINCOLOUR,DARKCOLOUR);
	addtriangle_diffsides_mono(&hydromesh,&on,
				   -1.5f,-0.85f,-7.0f,	-1.5f,-0.85f,-6.0f,	1.5f,-0.85f,-6.0f,
				   MAINCOLOUR,DARKCOLOUR);
	*/
	/*
	// Backdrop

	on = 0;
	
	// Floor (total 512 on 0)
	GLfloat x,z;
	GLfloat y = -2.0f;
	for (x = -64.0f; x < 64.0f; x += 8.0f) {
		for (z = -64.0f; z < 64.0f; z += 8.0f) {
			addtriangle_mono(&backmesh,&on,
					 x,y,z,	x,y,z + 8.0f,	x + 8.0f,y,z,
					 RED);
			addtriangle_mono(&backmesh,&on,
					 x + 8.0f,y,z + 8.0f,	x + 8.0f,y,z,	x,y,z + 8.0f,
					 BLUE);
		}
	}
	
	// Walls (total 32 on 512)
	GLfloat top = y + 4.0f;
	addtriangle_diffsides_mono_reflect(&backmesh,&on,1,0,1,
					   60.0f,top,60.0f,	60.0f,y,60.0f,	0.0f,y,64.0f,
					   GREEN,YELLOW);
	addtriangle_diffsides_mono_reflect(&backmesh,&on,1,0,1,
					   60.0f,top,60.0f,	0.0f,y,64.0f,	0.0f,top,64.0f,
					   GREEN,YELLOW);
	addtriangle_diffsides_mono_reflect(&backmesh,&on,1,0,1,
					   60.0f,y,60.0f,	60.0f,top,60.0f,	64.0f,y,0.0f,
					   GREEN,YELLOW);
	addtriangle_diffsides_mono_reflect(&backmesh,&on,1,0,1,
					   60.0f,top,60.0f,	64.0f,top,0.0f,	64.0f,y,0.0f,
					   GREEN,YELLOW);
	*/
	//printf("%d\n",on);
	//addtriangle_bothsides_mono_reflect(&backmesh,&on,1,1,1,
	//				   20.0f,20.0f,20.0f,	20.0f,20.0f,40.0f,	20.0f,40.0f,20.0f,
	//				   RED);
	//addtriangle_bothsides_mono_reflect(&backmesh,&on,1,1,1,
	//				   0.0f,0.0f,200.0f,	20.0f,20.0f,40.0f,	20.0f,40.0f,20.0f,
	//				   BLUE);
}
