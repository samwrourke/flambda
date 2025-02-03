#define BACKTRIANGLES 129

GLfloat backvertices[BACKTRIANGLES * 3 * 3];
GLfloat backcolours[BACKTRIANGLES * 3 * 4];
struct Mesh backmesh = {NULL,BACKTRIANGLES * 3,backvertices,backcolours};

#define FLOOR DARKSLATEGRAY4
#define WALLIN DARKORCHID1
#define WALLOUT RED
#define STARTLINE0 BLACK
#define STARTLINE1 WHITE

#define CANYONTRIANGLES 186

GLfloat canyonvertices[CANYONTRIANGLES * 3 * 3];
GLfloat canyoncolours[CANYONTRIANGLES * 3 * 4];
struct Mesh canyonmesh = {NULL,CANYONTRIANGLES * 3,canyonvertices,canyoncolours};

#define CANYONFLOOR DARKORANGE4
#define CANYONWALLIN DARKORANGE
#define CANYONWALLOUT CORAL4

void setbackmeshes(void) {
	GLfloat y = -2.0f;
	
	int on = 0;
	
	// Bottom strip (total 12 on 0)
	addtriangle_mono(&backmesh,&on,
			 512.0f,y,0.0f,	8.0f,y,0.0f,	8.0f,y,64.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 512.0f,y,64.0f,	512.0f,y,0.0f,	8.0f,y,64.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -8.0f,y,0.0f,	-544.0f,y,0.0f,	-512.0f,y,64.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -8.0f,y,64.0f,	-8.0f,y,0.0f,	-512.0f,y,64.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,0.0f,	512.0f,y + 2.0f,0.0f,	-544.0f,y,0.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,0.0f,	-544.0f,y + 2.0f,0.0f,	-544.0f,y,0.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -512.0f,y,64.0f,	448.0f,y + 2.0f,64.0f,	448.0f,y,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   448.0f,y + 2.0f,64.0f,	-512.0f,y,64.0f,	-512.0f,y + 2.0f,64.0f,
				   WALLIN,WALLOUT);
	
	// Finish line (total 32 on 12)
	GLfloat i;
	for (i = 0.0f; i < 64.0f; i += 16.0f) {
		addtriangle_mono(&backmesh,&on,
				 8.0f,y,i,	0.0f,y,i,	8.0f,y,i + 8.0f,
				 STARTLINE0);
		addtriangle_mono(&backmesh,&on,
				 0.0f,y,i,	0.0f,y,i + 8.0f,	8.0f,y,i + 8.0f,
				 STARTLINE0);
		addtriangle_mono(&backmesh,&on,
				 0.0f,y,i,	-8.0f,y,i,	0.0f,y,i + 8.0f,
				 STARTLINE1);
		addtriangle_mono(&backmesh,&on,
				 -8.0f,y,i,	-8.0f,y,i + 8.0f,	0.0f,y,i + 8.0f,
				 STARTLINE1);
		addtriangle_mono(&backmesh,&on,
				 8.0f,y,i + 8.0f,	0.0f,y,i + 8.0f,	8.0f,y,i + 16.0f,
				 STARTLINE1);
		addtriangle_mono(&backmesh,&on,
				 0.0f,y,i + 8.0f,	0.0f,y,i + 16.0f,	8.0f,y,i + 16.0f,
				 STARTLINE1);
		addtriangle_mono(&backmesh,&on,
				 0.0f,y,i + 8.0f,	-8.0f,y,i + 8.0f,	0.0f,y,i + 16.0f,
				 STARTLINE0);
		addtriangle_mono(&backmesh,&on,
				 -8.0f,y,i + 8.0f,	-8.0f,y,i + 16.0f,	0.0f,y,i + 16.0f,
				 STARTLINE0);
	}
	
	// Corner (total 10 on 44)
	addtriangle_mono(&backmesh,&on,
			 576.0f,y,64.0f,	512.0f,y,0.0f,	512.0f,y,64.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 512.0f,y,128.0f,	512.0f,y,64.0f,	448.0f,y,64.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,0.0f,	512.0f,y,0.0f,	576.0f,y,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,0.0f,	576.0f,y,64.0f,	576.0f,y + 2.0f,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,128.0f,	512.0f,y,128.0f,	448.0f,y,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,128.0f,	448.0f,y,64.0f,	448.0f,y + 2.0f,64.0f,
				   WALLIN,WALLOUT);
	
			 
	// Upwards strip (total 10 on 54)
	addtriangle_mono(&backmesh,&on,
			 576.0f,y,64.0f,	512.0f,y,64.0f,	512.0f,y,576.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 576.0f,y,64.0f,	512.0f,y,576.0f,	576.0f,y,576.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   576.0f,y,576.0f,	576.0f,y + 2.0f,576.0f,	576.0f,y,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   576.0f,y + 2.0f,576.0f,	576.0f,y + 2.0f,64.0f,	576.0f,y,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,576.0f,	512.0f,y,576.0f,	512.0f,y,128.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,576.0f,	512.0f,y,128.0f,	512.0f,y + 2.0f,128.0f,
				   WALLIN,WALLOUT);
				   
	// Top corner (total 15 on 64)
	addtriangle_mono(&backmesh,&on,
			 512.0f,y,576.0f,	512.0f,y,640.0f,	576.0f,y,576.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 512.0f,y,576.0f,	448.0f,y,576.0f,	512.0f,y,640.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 448.0f,y,576.0f,	403.0f,y,640.0f,	512.0f,y,640.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,640.0f,	576.0f,y + 2.0f,576.0f,	576.0f,y,576.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,640.0f,	512.0f,y + 2.0f,640.0f,	576.0f,y + 2.0f,576.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,640.0f,	403.0f,y,640.0f,	403.0f,y + 2.0f,640.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y + 2.0f,640.0f,	512.0f,y,640.0f,	403.0f,y + 2.0f,640.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,576.0f,	448.0f,y + 2.0f,576.0f,	448.0f,y,576.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   512.0f,y,576.0f,	512.0f,y + 2.0f,576.0f,	448.0f,y + 2.0f,576.0f,
				   WALLIN,WALLOUT);
				   
	// Diagonal strip (total 10 on 79)
	addtriangle_mono(&backmesh,&on,
			 448.0f,y,576.0f,	64.0f,y,192.0f,	403.0f,y,640.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 64.0f,y,192.0f,	19.0f,y,256.0f,	403.0f,y,640.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   448.0f,y,576.0f,	64.0f,y + 2.0f,192.0f,	64.0f,y,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   448.0f,y,576.0f,	448.0f,y + 2.0f,576.0f,	64.0f,y + 2.0f,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   19.0f,y,256.0f,	403.0f,y + 2.0f,640.0f,	403.0f,y,640.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   19.0f,y,256.0f,	19.0f,y + 2.0f,256.0f,	403.0f,y + 2.0f,640.0f,
				   WALLIN,WALLOUT);
	
	// Back strip (total 10 on 89)
	addtriangle_mono(&backmesh,&on,
			 64.0f,y,192.0f,	-512.0f,y,192.0f,	19.0f,y,256.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -512.0f,y,192.0f,	-544.0f,y,256.0f,	19.0f,y,256.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   64.0f,y,192.0f,	-512.0f,y + 2.0f,192.0f,	-512.0f,y,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   64.0f,y,192.0f,	64.0f,y + 2.0f,192.0f,	-512.0f,y + 2.0f,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   19.0f,y,256.0f,	-544.0f,y,256.0f,	-544.0f,y + 2.0f,256.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   19.0f,y + 2.0f,256.0f,	19.0f,y,256.0f,	-544.0f,y + 2.0f,256.0f,
				   WALLIN,WALLOUT);
				   
	// Last corner (total 30 on 99)
	addtriangle_mono(&backmesh,&on,
			 -512.0f,y,192.0f,	-608.0f,y,192.0f,	-544.0f,y,256.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -544.0f,y,0.0f,	-608.0f,y,64.0f,	-512.0f,y,64.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -512.0f,y,192.0f,	-544.0f,y,160.0f,	-544.0f,y,192.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -512.0f,y,64.0f,	-544.0f,y,64.0f,	-544.0f,y,96.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -544.0f,y,64.0f,	-608.0f,y,192.0f,	-544.0f,y,192.0f,
			 FLOOR);
	addtriangle_mono(&backmesh,&on,
			 -544.0f,y,64.0f,	-608.0f,y,64.0f,	-608.0f,y,192.0f,
			 FLOOR);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -608.0f,y,192.0f,	-608.0f,y + 2.0f,192.0f,	-544.0f,y,256.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -608.0f,y + 2.0f,192.0f,	-544.0f,y + 2.0f,256.0f,	-544.0f,y,256.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -608.0f,y,192.0f,	-608.0f,y,64.0f,	-608.0f,y + 2.0f,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -608.0f,y,64.0f,	-608.0f,y + 2.0f,64.0f,	-608.0f,y + 2.0f,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -608.0f,y,64.0f,	-544.0f,y,0.0f,	-608.0f,y + 2.0f,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -544.0f,y,0.0f,	-544.0f,y + 2.0f,0.0f,	-608.0f,y + 2.0f,64.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -544.0f,y + 2.0f,160.0f,	-544.0f,y,160.0f,	-512.0f,y,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -544.0f,y + 2.0f,160.0f,	-512.0f,y,192.0f,	-512.0f,y + 2.0f,192.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -544.0f,y + 2.0f,160.0f,	-544.0f,y,96.0f,	-544.0f,y,160.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -544.0f,y + 2.0f,160.0f,	-544.0f,y + 2.0f,96.0f,	-544.0f,y,96.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -512.0f,y,64.0f,	-544.0f,y,96.0f,	-544.0f,y + 2.0f,96.0f,
				   WALLIN,WALLOUT);
	addtriangle_diffsides_mono(&backmesh,&on,
				   -512.0f,y + 2.0f,64.0f,	-512.0f,y,64.0f,	-544.0f,y + 2.0f,96.0f,
				   WALLIN,WALLOUT);
	
	// ================ CANYON ================ 

	// Home (total 12 on 0)
	on = 0;
	addtriangle_mono(&canyonmesh,&on,
			 288.0f,y,0.0f,	8.0f,y,0.0f,	8.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 256.0f,y,64.0f,	288.0f,y,0.0f,	8.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -8.0f,y,0.0f,	-192.0f,y,0.0f,	-256.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -8.0f,y,64.0f,	-8.0f,y,0.0f,	-256.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   288.0f,y,0.0f,	288.0f,y + 2.0f,0.0f,	-192.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   288.0f,y + 2.0f,0.0f,	-192.0f,y + 2.0f,0.0f,	-192.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -256.0f,y,64.0f,	256.0f,y + 2.0f,64.0f,	256.0f,y,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   256.0f,y + 2.0f,64.0f,	-256.0f,y,64.0f,	-256.0f,y + 2.0f,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	
	// Finish line (total 32 on 12)
	for (i = 0.0f; i < 64.0f; i += 16.0f) {
		addtriangle_mono(&canyonmesh,&on,
				 8.0f,y,i,	0.0f,y,i,	8.0f,y,i + 8.0f,
				 STARTLINE0);
		addtriangle_mono(&canyonmesh,&on,
				 0.0f,y,i,	0.0f,y,i + 8.0f,	8.0f,y,i + 8.0f,
				 STARTLINE0);
		addtriangle_mono(&canyonmesh,&on,
				 0.0f,y,i,	-8.0f,y,i,	0.0f,y,i + 8.0f,
				 STARTLINE1);
		addtriangle_mono(&canyonmesh,&on,
				 -8.0f,y,i,	-8.0f,y,i + 8.0f,	0.0f,y,i + 8.0f,
				 STARTLINE1);
		addtriangle_mono(&canyonmesh,&on,
				 8.0f,y,i + 8.0f,	0.0f,y,i + 8.0f,	8.0f,y,i + 16.0f,
				 STARTLINE1);
		addtriangle_mono(&canyonmesh,&on,
				 0.0f,y,i + 8.0f,	0.0f,y,i + 16.0f,	8.0f,y,i + 16.0f,
				 STARTLINE1);
		addtriangle_mono(&canyonmesh,&on,
				 0.0f,y,i + 8.0f,	-8.0f,y,i + 8.0f,	0.0f,y,i + 16.0f,
				 STARTLINE0);
		addtriangle_mono(&canyonmesh,&on,
				 -8.0f,y,i + 8.0f,	-8.0f,y,i + 16.0f,	0.0f,y,i + 16.0f,
				 STARTLINE0);
	}
	
	// Diag (total 10 on 44)
	addtriangle_mono(&canyonmesh,&on,
			 832.0f,y,544.0f,	288.0f,y,0.0f,	256.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 768.0f,y,576.0f,	832.0f,y,544.0f,	256.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   832.0f,y,544.0f,	832.0f,y + 2.0f,544.0f,	288.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   832.0f,y + 2.0f,544.0f,	288.0f,y + 2.0f,0.0f,	288.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   256.0f,y,64.0f,	768.0f,y + 2.0f,576.0f,	768.0f,y,576.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   768.0f,y + 2.0f,576.0f,	256.0f,y,64.0f,	256.0f,y + 2.0f,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);	
				   
	// C1 (total 20 on 54)
	addtriangle_mono(&canyonmesh,&on,
			 768.0f,y,576.0f,	832.0f,y,608.0f,	832.0f,y,544.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   832.0f,y,608.0f,	832.0f,y + 2.0f,608.0f,	832.0f,y,544.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   832.0f,y + 2.0f,608.0f,	832.0f,y + 2.0f,544.0f,	832.0f,y,544.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_mono(&canyonmesh,&on,
			 768.0f,y,576.0f,	800.0f,y,640.0f,	832.0f,y,608.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   800.0f,y,640.0f,	800.0f,y + 2.0f,640.0f,	832.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   800.0f,y + 2.0f,640.0f,	832.0f,y + 2.0f,608.0f,	832.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_mono(&canyonmesh,&on,
			 768.0f,y,576.0f,	736.0f,y,608.0f,	800.0f,y,640.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   768.0f,y,576.0f,	736.0f,y + 2.0f,608.0f,	736.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   768.0f,y,576.0f,	768.0f,y + 2.0f,576.0f,	736.0f,y + 2.0f,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_mono(&canyonmesh,&on,
			 736.0f,y,608.0f,	736.0f,y,672.0f,	800.0f,y,640.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y,672.0f,	736.0f,y + 2.0f,672.0f,	800.0f,y,640.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y + 2.0f,672.0f,	800.0f,y + 2.0f,640.0f,	800.0f,y,640.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	
	// Split lead (total 10 on 74)
	addtriangle_mono(&canyonmesh,&on,
			 736.0f,y,608.0f,	480.0f,y,608.0f,	736.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 480.0f,y,608.0f,	480.0f,y,672.0f,	736.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y,608.0f,	480.0f,y + 2.0f,608.0f,	480.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y,608.0f,	736.0f,y + 2.0f,608.0f,	480.0f,y + 2.0f,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y,672.0f,	480.0f,y,672.0f,	480.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   736.0f,y + 2.0f,672.0f,	736.0f,y,672.0f,	480.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);

	// Split (total 42 on 84)
	addtriangle_mono(&canyonmesh,&on,
			 480.0f,y,608.0f,	362.0f,y,640.0f,	480.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -22.0f,y,672.0f,	106.0f,y,640.0f,	-22.0f,y,608.0f,
			 CANYONFLOOR);
	
	addtriangle_mono(&canyonmesh,&on,
			 362.0f,y,640.0f,	234.0f,y,672.0f,	480.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 234.0f,y,672.0f,	234.0f,y,736.0f,	480.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 362.0f,y,640.0f,	480.0f,y,608.0f,	234.0f,y,608.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 234.0f,y,608.0f,	480.0f,y,608.0f,	234.0f,y,544.0f,
			 CANYONFLOOR);
	
	addtriangle_mono(&canyonmesh,&on,
			 106.0f,y,640.0f,	-22.0f,y,672.0f,	234.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 234.0f,y,672.0f,	-22.0f,y,672.0f,	234.0f,y,736.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 106.0f,y,640.0f,	234.0f,y,608.0f,	-22.0f,y,608.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 234.0f,y,608.0f,	234.0f,y,544.0f,	-22.0f,y,608.0f,
			 CANYONFLOOR);
			 
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   362.0f,y,640.0f,	234.0f,y + 2.0f,672.0f,	234.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   362.0f,y,640.0f,	362.0f,y + 2.0f,640.0f,	234.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   362.0f,y,640.0f,	234.0f,y,608.0f,	234.0f,y + 2.0f,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   362.0f,y,640.0f,	234.0f,y + 2.0f,608.0f,	362.0f,y + 2.0f,640.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   106.0f,y,640.0f,	234.0f,y,672.0f,	234.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   106.0f,y + 2.0f,640.0f,	106.0f,y,640.0f,	234.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   106.0f,y,640.0f,	234.0f,y + 2.0f,608.0f,	234.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   106.0f,y + 2.0f,640.0f,	234.0f,y + 2.0f,608.0f,	106.0f,y,640.0f,
				   CANYONWALLIN,CANYONWALLOUT);
				   
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y,736.0f,	234.0f,y + 2.0f,736.0f,	480.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,736.0f,	480.0f,y + 2.0f,672.0f,	480.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,544.0f,	234.0f,y,544.0f,	480.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,544.0f,	480.0f,y,608.0f,	480.0f,y + 2.0f,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,736.0f,	234.0f,y,736.0f,	-22.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,736.0f,	-22.0f,y,672.0f,	-22.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y,544.0f,	234.0f,y + 2.0f,544.0f,	-22.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   234.0f,y + 2.0f,544.0f,	-22.0f,y + 2.0f,608.0f,	-22.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
				   
	// Split end (total 10 on 126)
	addtriangle_mono(&canyonmesh,&on,
			 -22.0f,y,608.0f,	-320.0f,y,608.0f,	-22.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -320.0f,y,608.0f,	-384.0f,y,672.0f,	-22.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -22.0f,y,608.0f,	-320.0f,y + 2.0f,608.0f,	-320.0f,y,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -22.0f,y,608.0f,	-22.0f,y + 2.0f,608.0f,	-320.0f,y + 2.0f,608.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -22.0f,y,672.0f,	-384.0f,y,672.0f,	-384.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -22.0f,y + 2.0f,672.0f,	-22.0f,y,672.0f,	-384.0f,y + 2.0f,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
	
	// D1 (total 10 on 136)
	addtriangle_mono(&canyonmesh,&on,
			 -320.0f,y,608.0f,	-320.0f,y,0.0f,	-384.0f,y,672.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -320.0f,y,0.0f,	-384.0f,y,64.0f,	-384.0f,y,672.0f,
			 CANYONFLOOR);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -320.0f,y,608.0f,	-320.0f,y + 2.0f,0.0f,	-320.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -320.0f,y,608.0f,	-320.0f,y + 2.0f,608.0f,	-320.0f,y + 2.0f,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,64.0f,	-384.0f,y + 2.0f,64.0f,	-384.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y + 2.0f,64.0f,	-384.0f,y + 2.0f,672.0f,	-384.0f,y,672.0f,
				   CANYONWALLIN,CANYONWALLOUT);
				   
	// Chic (total 10 on 146)
	addtriangle_mono(&canyonmesh,&on,
			 -320.0f,y,0.0f,	-384.0f,y,0.0f,	-384.0f,y,64.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -384.0f,y,0.0f,	-448.0f,y,64.0f,	-384.0f,y,64.0f,
			 CANYONFLOOR);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -320.0f,y,0.0f,	-384.0f,y + 2.0f,0.0f,	-384.0f,y,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -320.0f,y,0.0f,	-320.0f,y + 2.0f,0.0f,	-384.0f,y + 2.0f,0.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,64.0f,	-448.0f,y,64.0f,	-448.0f,y + 2.0f,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y + 2.0f,64.0f,	-384.0f,y,64.0f,	-448.0f,y + 2.0f,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
				   
	// D2 (total 10 on 156)
	addtriangle_mono(&canyonmesh,&on,
			 -384.0f,y,0.0f,	-384.0f,y,-64.0f,	-448.0f,y,64.0f,
		 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -384.0f,y,-64.0f,	-448.0f,y,-128.0f,	-448.0f,y,64.0f,
			 CANYONFLOOR);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,0.0f,	-384.0f,y + 2.0f,-64.0f,	-384.0f,y,-64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,0.0f,	-384.0f,y + 2.0f,0.0f,	-384.0f,y + 2.0f,-64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -448.0f,y,-128.0f,	-448.0f,y + 2.0f,-128.0f,	-448.0f,y,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -448.0f,y + 2.0f,-128.0f,	-448.0f,y + 2.0f,64.0f,	-448.0f,y,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
				   
	// C3 (total 10 on 166)
	addtriangle_mono(&canyonmesh,&on,
			 -384.0f,y,-64.0f,	-192.0f,y,-128.0f,	-448.0f,y,-128.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -384.0f,y,-64.0f,	-256.0f,y,-64.0f,	-192.0f,y,-128.0f,
			 CANYONFLOOR);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -192.0f,y,-128.0f,	-192.0f,y + 2.0f,-128.0f,	-448.0f,y,-128.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -192.0f,y + 2.0f,-128.0f,	-448.0f,y + 2.0f,-128.0f,	-448.0f,y,-128.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,-64.0f,	-256.0f,y + 2.0f,-64.0f,	-256.0f,y,-64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -384.0f,y,-64.0f,	-384.0f,y + 2.0f,-64.0f,	-256.0f,y + 2.0f,-64.0f,
				   CANYONWALLIN,CANYONWALLOUT);

	// Last (total 10 on 176)
	addtriangle_mono(&canyonmesh,&on,
			 -256.0f,y,-64.0f,	-192.0f,y,0.0f,	-192.0f,y,-128.0f,
			 CANYONFLOOR);
	addtriangle_mono(&canyonmesh,&on,
			 -256.0f,y,-64.0f,	-256.0f,y,64.0f,	-192.0f,y,0.0f,
			 CANYONFLOOR);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -192.0f,y,0.0f,	-192.0f,y + 2.0f,0.0f,	-192.0f,y,-128.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -192.0f,y + 2.0f,0.0f,	-192.0f,y + 2.0f,-128.0f,	-192.0f,y,-128.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -256.0f,y,-64.0f,	-256.0f,y + 2.0f,64.0f,	-256.0f,y,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
 	addtriangle_diffsides_mono(&canyonmesh,&on,
				   -256.0f,y,-64.0f,	-256.0f,y + 2.0f,-64.0f,	-256.0f,y + 2.0f,64.0f,
				   CANYONWALLIN,CANYONWALLOUT);
}