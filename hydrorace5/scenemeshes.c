struct Mesh noscene = {NULL,0,NULL,NULL};

#define CANYONSCENETRIANGLES 1226

GLfloat canyonscenevertices[CANYONSCENETRIANGLES * 3 * 3];
GLfloat canyonscenecolours[CANYONSCENETRIANGLES * 3 * 4];
struct Mesh canyonscenemesh = {NULL,CANYONSCENETRIANGLES * 3,canyonscenevertices,canyonscenecolours};

#define CANYONSCENEFLOOR TAN4
#define CANYONSCENEWALLIN DARKORANGE
#define CANYONSCENEWALLOUT CORAL4
#define SKY BLUE
#define CANYONROCK0 DARKORANGE4
#define CANYONROCK1 CORAL4

void addcactus(struct Mesh *mesh,int *n,
	       char axis,int ntris,
	       GLfloat h0,GLfloat h1,GLfloat h2,GLfloat h3,GLfloat rad0,GLfloat rad1,GLfloat rad2,GLfloat rad3,GLfloat w0,GLfloat w1,
	       GLfloat x,GLfloat y,GLfloat z,
	       GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0) {
	       //GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	// Adds 15n triangles
	addcylinder_mono(mesh,n,
			 'y',rad0,h0,ntris,0.0,
			 x,y,z,
			 r0,g0,b0,a0);
	adddisc_mono(mesh,n,
		     'y',rad0,ntris,0.5,
		     x,y + h0,z,
		     r0,g0,b0,a0);
	switch (axis) {
		case 'x':
			addcylinder_mono(mesh,n,
				         'x',rad1,w0 + w1,ntris,0.0,
				         x - w0,y + h1,z,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'x',rad1,-ntris,0.0,
				     x - w0,y + h1,z,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'x',rad1,ntris,0.5,
				     x + w1,y + h1,z,
				     r0,g0,b0,a0);
			addcylinder_mono(mesh,n,
				         'y',rad2,h2,ntris,0.0,
				         x - w0 + rad2,y + h1,z,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad2,-ntris,0.0,
				     x - w0 + rad2,y + h1,z,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad2,ntris,0.0,
				     x - w0 + rad2,y + h1 + h2,z,
				     r0,g0,b0,a0);
			addcylinder_mono(mesh,n,
				         'y',rad3,h3,ntris,0.0,
				         x + w1 - rad3,y + h1,z,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad3,-ntris,0.0,
				     x + w1 - rad2,y + h1,z,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad3,ntris,0.0,
				     x + w1 - rad3,y + h1 + h3,z,
				     r0,g0,b0,a0);
			break;
		case 'z':
			addcylinder_mono(mesh,n,
				         'z',rad1,w0 + w1,ntris,0.0,
				         x,y + h1,z - w0,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'z',rad1,-ntris,0.0,
				     x,y + h1,z - w0,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'z',rad1,ntris,0.0,
				     x,y + h1,z + w1,
				     r0,g0,b0,a0);
			addcylinder_mono(mesh,n,
				         'y',rad2,h2,ntris,0.0,
				         x,y + h1,z - w0 + rad2,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad2,-ntris,0.0,
				     x,y + h1,z - w0 + rad2,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad2,ntris,0.0,
				     x,y + h1 + h2,z - w0 + rad2,
				     r0,g0,b0,a0);	
			addcylinder_mono(mesh,n,
				         'y',rad3,h3,ntris,0.0,
				         x,y + h1,z + w1 - rad3,
				         r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad3,-ntris,0.0,
				     x,y + h1,z + w1 - rad3,
				     r0,g0,b0,a0);
			adddisc_mono(mesh,n,
				     'y',rad3,ntris,0.0,
				     x,y + h1 + h3,z + w1 - rad3,
				     r0,g0,b0,a0);	
			break;
		default:
			fprintf(stderr,"Axis must be x or z");
	}
}

void setscenemeshes(void) {
	GLfloat y = -2.0f;
	
	int on = 0;
	
	// Sky cylinder (total 24 on 0)
	adddisc_grad(&canyonscenemesh,&on,
		     'y',50000.0f,8,0.0,
		     0.0f,y - 0.5f,0.0f,
		     BLACK,CANYONSCENEFLOOR);
	addcylinder_grad(&canyonscenemesh,&on,
			 'y',50000.0f,50000.0f,-8,0.0,
			 0.0f,y - 0.5f,0.0f,
			 BLACK,SKY);

	// Cacti (total 1200 on 24)
	addcactus(&canyonscenemesh,&on,
		  'z',8,
		  19.0f,11.0f,10.0f,7.5f,1.9f,0.9f,1.2f,1.0f,5.0f,6.0f,
		  0.0f,y,128.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  25.0f,12.0f,9.0f,13.5f,1.8f,1.0f,0.5f,1.0f,7.0f,6.5f,
		  -128.0f,y,-128.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  23.0f,9.0f,15.0f,9.5f,1.7f,1.2f,1.3f,1.0f,5.0f,7.0f,
		  0.0f,y,1024.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'z',8,
		  23.0f,11.0f,10.0f,5.9f,1.9f,1.5f,1.0f,1.0f,6.7f,5.9f,
		  64.0f,y,900.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'z',8,
		  23.0f,10.0f,11.0f,9.5f,1.9f,1.0f,1.5f,1.0f,6.0f,6.5f,
		  1024.0f,y,-1024.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'z',8,
		  21.0f,10.0f,10.0f,10.0f,2.0f,1.5f,1.75f,1.0f,7.5f,5.0f,
		  220.0f,y,650.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  23.0f,10.0f,11.0f,9.5f,1.9f,1.0f,1.5f,1.0f,6.0f,6.5f,
		  -500.0f,y,-500.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  23.0f,11.0f,10.0f,9.5f,1.9f,1.0f,1.5f,1.0f,6.0f,6.5f,
		  256.0f,y,-64.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  20.0f,12.0f,11.0f,9.5f,1.9f,1.0f,1.5f,1.0f,6.0f,6.5f,
		  -1024.0f,y,32.0f,
		  GREEN4);
	addcactus(&canyonscenemesh,&on,
		  'x',8,
		  23.0f,10.0f,11.0f,9.5f,1.9f,1.0f,1.5f,1.0f,6.0f,6.5f,
		  567.0f,y,-78.0f,
		  GREEN4);
		  
	// Rocks (total 2 on 1224)
	addtriangle_mono(&canyonscenemesh,&on,
			 1950.0f,y,2048.0f,	2176.0f,y + 64,1920.0f,	2304.0f,y,1792.0f,
			 CANYONROCK0);
	addtriangle_mono(&canyonscenemesh,&on,
			 2176.0f,y + 64,1920.0f,	2504.0f,y,1592.0f,	2304.0f,y,1792.0f,
			 CANYONROCK1);
}