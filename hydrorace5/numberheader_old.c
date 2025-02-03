GLfloat numbermatrix[16] = scalematrix_m(1.0f,1.0f,1.0f,1.0f);

#define ONETRIANGLES 5

GLfloat onevertices[ONETRIANGLES * 3 * 3];
GLfloat onecolours[ONETRIANGLES * 3 * 4];
struct Mesh onemesh = {numbermatrix,ONETRIANGLES * 3,onevertices,onecolours};

// Pallete
#define ONECOLOUR GOLD1

#define TWOTRIANGLES 12

GLfloat twovertices[TWOTRIANGLES * 3 * 3];
GLfloat twocolours[TWOTRIANGLES * 3 * 4];
struct Mesh twomesh = {numbermatrix,TWOTRIANGLES * 3,twovertices,twocolours};

// Pallete
#define TWOCOLOUR GREY

#define THREETRIANGLES 19

GLfloat threevertices[THREETRIANGLES * 3 * 3];
GLfloat threecolours[THREETRIANGLES * 3 * 4];
struct Mesh threemesh = {numbermatrix,THREETRIANGLES * 3,threevertices,threecolours};

// Pallete
#define THREECOLOUR DARKORANGE3

void setnumbermeshes(void) {
	struct Mesh *meshptr = &onemesh;

	int on = 0;
	addtriangle_mono(meshptr,&on,
			 -3.5f,6.0f,0.0f,	1.0f,6.0f,0.0f,	1.0f,10.5f,0.0f,
			 ONECOLOUR);
	addtriangle_mono(meshptr,&on,
			 1.0f,6.0f,0.0f,	-1.0f,6.0f,0.0f,	1.0f,-8.0f,0.0f,
			 ONECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -1.0f,6.0f,0.0f,	-1.0f,-8.0f,0.0f,	1.0f,-8.0f,0.0f,
			 ONECOLOUR);
	addtriangle_mono(meshptr,&on,
			 3.0f,-8.0f,0.0f,	-3.0f,-8.0f,0.0f,	3.0f,-10.0f,0.0f,
			 ONECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -3.0f,-8.0f,0.0f,	-3.0f,-10.0f,0.0f,	3.0f,-10.0f,0.0f,
			 ONECOLOUR);
	
	meshptr = &twomesh;
	on = 0;
	addtriangle_mono(meshptr,&on,
			 7.0f,-8.0f,0.0f,	-7.0f,-8.0f,0.0f,	7.0f,-10.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 -7.0f,-8.0f,0.0f,	-7.0f,-10.0f,0.0f,	7.0f,-10.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 -7.0f,-8.0f,0.0f,	0.0f,-8.0f,0.0f,	5.0f,-6.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 -7.0f,-8.0f,0.0f,	5.0f,-6.0f,0.0f,	3.0f,-5.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 5.0f,-6.0f,0.0f,	5.5f,-1.0f,0.0f,	3.0f,-5.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 5.5f,-1.0f,0.0f,	3.8f,-1.0f,0.0f,	3.0f,-5.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 5.5f,-1.0f,0.0f,	3.5f,4.5f,0.0f,	3.8f,-1.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 3.5f,4.5f,0.0f,	2.5f,3.5f,0.0f,	3.8f,-1.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 3.5f,4.5f,0.0f,	0.0f,6.0f,0.0f,	2.5f,3.5f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 0.0f,6.0f,0.0f,	-2.0f,5.0f,0.0f,	2.5f,3.5f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 0.0f,6.0f,0.0f,	-4.0f,5.5f,0.0f,	-2.0f,5.0f,0.0f,
			 TWOCOLOUR);
	addtriangle_mono(meshptr,&on,
			 -4.0f,5.5f,0.0f,	-6.0f,4.0f,0.0f,	-2.0f,5.0f,0.0f,
			 TWOCOLOUR);
	
	meshptr = &threemesh;
	on = 0;
	addtriangle_mono(meshptr,&on,
			 2.0f,0.6f,0.0f,	-5.0f,0.6f,0.0f,	2.0f,-0.6f,0.0f,
			 THREECOLOUR);
	addtriangle_mono(meshptr,&on,
			 -5.0f,0.6f,0.0f,	-5.0f,-0.6f,0.0f,	2.0f,-0.6f,0.0f,
			 THREECOLOUR);
	addtriangle_mono(meshptr,&on,
			 2.0f,0.6f,0.0f,	2.0f,-0.6f,0.0f,	3.0f,0.0f,0.0f,
			 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,0.6f,0.0f,	3.0f,0.0f,0.0f,	5.0f,4.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,0.6f,0.0f,	5.0f,4.0f,0.0f,	3.5f,4.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,7.0f,0.0f,	5.0f,4.0f,0.0f,	3.0f,8.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,7.0f,0.0f,	3.5f,4.0f,0.0f,	5.0f,4.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,7.0f,0.0f,	3.0f,8.0f,0.0f,	-1.0f,9.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 2.0f,7.0f,0.0f,	-1.0f,9.0f,0.0f,	-2.0f,8.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 -1.0f,9.0f,0.0f,	-5.0f,8.5f,0.0f,	-2.0f,8.0f,0.0f,
				 THREECOLOUR);
	addtriangle_mono_reflect(meshptr,&on,0,1,0,
				 -5.0f,8.5f,0.0f,	-7.0f,7.0f,0.0f,	-2.0f,8.0f,0.0f,
				 THREECOLOUR);
}