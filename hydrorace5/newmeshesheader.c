#define RACETRIANGLES 271

GLfloat racevertices[RACETRIANGLES * 3 * 3];
GLfloat racecolours[RACETRIANGLES * 3 * 4];
struct Mesh racemesh = {NULL,RACETRIANGLES * 3,racevertices,racecolours};

// Pallete
#define MAINCOLOUR BLUE4
#define DARKCOLOUR 0.0f,0.0f,0.15f,1.0f
#define WINDOW BLACK
#define ENGINE GREY50
#define CONE GREY20
#define FIRE RED
#define TIP CYAN

void setmeshes(void) {
	struct Mesh *meshptr = &racemesh;

	int on = 0;

	// Underside (total 4 on 0)
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 0.0f,-1.0f,10.0f,	0.0f,-1.0f,-6.0f,	5.0f,-1.0f,8.0f,
				 DARKCOLOUR);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 9.0f,-1.0f,-6.0f,	5.0f,-1.0f,8.0f,	0.0f,-1.0f,-6.0f,
				 DARKCOLOUR);

	// Cockpit (total 8 on 4)
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 0.0f,0.0f,8.0f,	2.0f,0.0f,6.0f,	0.0f,2.0f,2.0f,
				 WINDOW);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 2.0f,0.0f,6.0f,	2.0f,0.0f,2.0f,	0.0f,2.0f,2.0f,
				 WINDOW);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 2.0f,0.0f,2.0f,	2.0f,0.0f,-6.0f,	0.0f,0.0f,-6.0f,
				 ENGINE);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 2.0f,0.0f,2.0f,	0.0f,0.0f,-6.0f,	0.0f,2.0f,2.0f,
				 MAINCOLOUR);
	
	// Body (total 8 on 12)
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 0.0f,-1.0f,10.0f,	5.0f,-1.0f,8.0f,	0.0f,0.0f,8.0f,
				 MAINCOLOUR);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 5.0f,-1.0f,8.0f,	2.0f,0.0f,6.0f,	0.0f,0.0f,8.0f,
				 MAINCOLOUR);
	addtriangle_reflect(meshptr,&on,1,0,0,
			    9.0f,-1.0f,-6.0f,	2.0f,0.0f,-6.0f,	5.0f,-1.0f,8.0f,
			    TIP,MAINCOLOUR,MAINCOLOUR);
	addtriangle_mono_reflect(meshptr,&on,1,0,0,
				 2.0f,0.0f,-6.0f,	2.0f,0.0f,6.0f,	5.0f,-1.0f,8.0f,
				 MAINCOLOUR);

	// Back (total 3 on 20)
	addtriangle_mono(meshptr,&on,
			 0.0f,-1.0f,-6.0f,	-2.0f,0.0f,-6.0f,	2.0f,0.0f,-6.0f,
			 MAINCOLOUR);
	addtriangle_reflect(meshptr,&on,1,0,0,
			    0.0f,-1.0f,-6.0f,	2.0f,0.0f,-6.0f,	9.0f,-1.0f,-6.0f,
			    MAINCOLOUR,MAINCOLOUR,TIP);

	// Engines (total 240 on 23)
	addfustrum_mono(meshptr,&on,
			'z',0.85f,0.8f,2.0f,8,0.0,
			2.0f,0.8f,-5.0f,
			ENGINE);
	addfustrum_mono(meshptr,&on,
			'z',0.7f,0.85f,3.0f,8,0.5,
			2.0f,0.8f,-8.0f,
			ENGINE);
	addfustrum_mono(meshptr,&on,
			'z',0.7f,0.85f,3.0f,-8,0.5,
			2.0f,0.8f,-8.0f,
			ENGINE);
	addfustrum_grad(meshptr,&on,
			'z',0.6f,0.8f,2.0f,-8,0.0,
			2.0f,0.8f,-5.0f,
			CONE,ENGINE);
	addcone_mono(meshptr,&on,
		     'z',0.6f,3.0f,8,0.0,
		     2.0f,0.8f,-5.0f,
		     CONE);
	addfustrum_mono(meshptr,&on,
			'z',0.5f,0.7f,1.0f,8,0.5,
			2.0f,0.8f,-8.0f,
			ENGINE);
	addfustrum_mono(meshptr,&on,
			'z',0.5f,0.7f,1.0f,-8,0.5,
			2.0f,0.8f,-8.0f,
			ENGINE);
	adddisc_mono(meshptr,&on,
		     'z',0.725f,-16,0.5,
		     2.0f,0.8f,-7.0f,
		     FIRE);
		     
	addfustrum_mono(meshptr,&on,	'z',0.85f,0.8f,2.0f,8,0.0,	-2.0f,0.8f,-5.0f,	ENGINE);
	addfustrum_mono(meshptr,&on,	'z',0.7f,0.85f,3.0f,8,0.5,	-2.0f,0.8f,-8.0f,	ENGINE);
	addfustrum_mono(meshptr,&on,	'z',0.7f,0.85f,3.0f,-8,0.5,	-2.0f,0.8f,-8.0f,	ENGINE);
	addfustrum_grad(meshptr,&on,	'z',0.6f,0.8f,2.0f,-8,0.0,	-2.0f,0.8f,-5.0f,	CONE,ENGINE);
	addcone_mono(meshptr,&on,	'z',0.6f,3.0f,8,0.0,	-2.0f,0.8f,-5.0f,	CONE);
	addfustrum_mono(meshptr,&on,	'z',0.5f,0.7f,1.0f,8,0.5,	-2.0f,0.8f,-8.0f,	ENGINE);
	addfustrum_mono(meshptr,&on,	'z',0.5f,0.7f,1.0f,-8,0.5,	-2.0f,0.8f,-8.0f,	ENGINE);
	adddisc_mono(meshptr,&on,	'z',0.725f,-16,0.5,	-2.0f,0.8f,-7.0f,	FIRE);
	
	// Fins (total 8 on 263)
	addtriangle_bothsides_reflect(meshptr,&on,1,0,0,
				      2.0f,1.46f,-8.0f,	2.0f,1.6f,-5.0f,	2.0f,3.5f,-9.0f,
				      MAINCOLOUR,MAINCOLOUR,TIP);
	addtriangle_bothsides_reflect(meshptr,&on,1,0,0,
				      2.0f,1.6f,-5.0f,	2.0f,3.5f,-9.0f,	2.0f,3.5f,-8.0f,
				      MAINCOLOUR,TIP,TIP);
}