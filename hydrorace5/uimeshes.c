#define SPEEDOTRIANGLES 117

GLfloat speedomatrix[16] = identitymatrix_m;
GLfloat speedovertices[SPEEDOTRIANGLES * 3 * 3];
GLfloat speedocolours[SPEEDOTRIANGLES * 3 * 4];
struct Mesh speedomesh = {speedomatrix,SPEEDOTRIANGLES * 3,speedovertices,speedocolours};

GLfloat speedoprojmatrix[16];

#define HANDTRIANGLES 2

GLfloat handvertices[HANDTRIANGLES * 3 * 3] = {0.0f,6.5f,-1.0f,	-0.5f,0.0f,-1.0f,	0.5f,0.0f,-1.0f,
					       0.0f,-2.0f,-1.0f,	0.5f,0.0f,-1.0f,	-0.5f,0.0f,-1.0f};
GLfloat handcolours[HANDTRIANGLES * 3 * 4] = {RED,BLACK,BLACK,BLACK,BLACK,BLACK};
struct Mesh handmesh = {speedomatrix,HANDTRIANGLES * 3,handvertices,handcolours};

void setuimeshes(void) {
	// Set mesh values
	int on = 0;
	adddisc_mono(&speedomesh,&on,
		     'z',7.0f,-32,0.0,
		     0.0f,0.0f,0.0f,
		     GREY10);
	addring_grad(&speedomesh,&on,
		     'z',7.5f,6.5f,-32,0.0,
		     0.0f,0.0f,-1.0f,
		     RED,YELLOW);
		     
	GLfloat temppoints0[21];
	gencirclepoints_range('z',7,degreestoradians(135.0),degreestoradians(45.0),
			      0.0f,4.0f,-0.5f,
			      temppoints0);
	GLfloat temppoints1[21];
	gencirclepoints_range('z',7,degreestoradians(135.0),degreestoradians(45.0),
			      0.3f,7.0f,-0.5f,
			      temppoints1);
	GLfloat temppoints2[21];
	gencirclepoints_range('z',7,degreestoradians(135.0),degreestoradians(45.0),
			      -0.3f,7.0f,-0.5f,
			      temppoints2);
	int i;
	for (i = 0; i < 21; i += 3) {
		addtriangle_mono(&speedomesh,&on,
				 temppoints0[i],temppoints0[i + 1],temppoints0[i + 2],	temppoints1[i],temppoints1[i + 1],temppoints1[i + 2],	temppoints2[i],temppoints2[i + 1],temppoints2[i + 2],
				 WHITE);
	}
		
	// Set matrix values
	rotatematrix(speedomatrix,0.3,1.0f,1.0f,0.0f);
}