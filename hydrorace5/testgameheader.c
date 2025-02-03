// Backdrop

#define BACKTRIANGLES 544

GLfloat backvertices[BACKTRIANGLES * 3 * 3];
GLfloat backcolours[BACKTRIANGLES * 3 * 4];
struct Mesh backmesh = {identity,BACKTRIANGLES * 3,backvertices,backcolours};

// Player

struct Plane player = {&hydromesh,0.0f,0.0f,0.0f,0.0f,0.0,0.0,{0.10f,0.97f,0.5,0.75}};

// Walls

struct Wall gamewallarray[8] = {{60.0f,60.0f,0.0f,64.0f},
					{-60.0f,60.0f,0.0f,64.0f},
					{60.0f,-60.0f,0.0f,-64.0f},
					{-60.0f,-60.0f,0.0f,-64.0f},
					{60.0f,60.0f,64.0f,0.0f},
					{60.0f,-60.0f,64.0f,0.0f},
					{-60.0f,60.0f,-64.0f,0.0f},
					{-60.0f,-60.0f,-64.0f,0.0f}};

struct Walls gamewalls = {8,gamewallarray};

void setgame(void) {
	int on = 0;
	
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
}