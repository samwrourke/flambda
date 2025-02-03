#define TITLETRIANGLES 12

GLfloat titlevertices[TITLETRIANGLES * 3 * 3];
GLfloat titlecolours[TITLETRIANGLES * 3 * 4];
struct Mesh titlemesh = {NULL,TITLETRIANGLES * 3,titlevertices,titlecolours};

// Pallete
#define TITLECOLOUR BLUE

void settitlemeshes(void) {
	struct Mesh *meshptr = &titlemesh;

	int on = 0;
	// Dash (total 2 on 0)
	addtriangle_mono(meshptr,&on,
			 -1.8f,0.5f,0.0f,	2.2f,0.5f,0.0f,	-2.2f,-0.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 1.8f,-0.5f,0.0f,	-2.2f,-0.5f,0.0f,	2.2f,0.5f,0.0f,
			 TITLECOLOUR);
			 
	// F (total 6 on 2)			 		 
	addtriangle_mono(meshptr,&on,
			 -6.8f,0.5f,0.0f,	-4.8f,0.5f,0.0f,	-7.2f,-0.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -5.2f,-0.5f,0.0f,	-7.2f,-0.5f,0.0f,	-4.8f,0.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -5.6f,3.5f,0.0f,	-1.6f,3.5f,0.0f,	-6.0f,2.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -2.0f,2.5f,0.0f,	-6.0f,2.5f,0.0f,	-1.6f,3.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -6.6f,3.5f,0.0f,	-5.6f,3.5f,0.0f,	-9.4f,-3.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -5.6f,3.5f,0.0f,	-8.4f,-3.5f,0.0f,	-9.4f,-3.5f,0.0f,
			 TITLECOLOUR);
			 
	// R (total 4 on 8)
	addtriangle_mono(meshptr,&on,
			 5.4f,3.5f,0.0f,	6.4f,3.5f,0.0f,	2.6f,-3.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 6.4f,3.5f,0.0f,	3.6f,-3.5f,0.0f,	2.6f,-3.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 4.7f,0.0f,0.0f,	5.2f,1.4f,0.0f,	6.1f,-3.5f,0.0f,
			 TITLECOLOUR);
	addtriangle_mono(meshptr,&on,
			 5.2f,1.4f,0.0f,	7.1f,-3.5f,0.0f,	6.1f,-3.5f,0.0f,
			 TITLECOLOUR);
}