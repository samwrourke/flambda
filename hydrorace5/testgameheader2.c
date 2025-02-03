#define TESTGAMESTATS {0.22f,0.02f,0.75,0.75,0.75,8.0f}

// Players

#define TESTNUMAIPLAYERS 4
//struct Plane testaiplayers[TESTNUMAIPLAYERS + 1];

struct Plane testaiplayers[TESTNUMAIPLAYERS + 1] = {{&racemesh,-16.0f,16.0f,0.0f,0.0f,270.0,0.0,TESTGAMESTATS,&blueiconmesh,0},
						    {&racemesh,-24.0f,48.0f,0.0f,0.0f,270.0,0.0,TESTGAMESTATS,&blueiconmesh,0},
						    {&racemesh,-48.0f,16.0f,0.0f,0.0f,270.0,0.0,TESTGAMESTATS,&blueiconmesh,0},
						    {&racemesh,-56.0f,48.0f,0.0f,0.0f,270.0,0.0,TESTGAMESTATS,&blueiconmesh,0},
						    {&racemesh,-80.0f,32.0f,0.0f,0.0f,270.0,0.0,TESTGAMESTATS,&rediconmesh,0}};

// Walls

#define TESTNUMWALLS 19

struct Wall testgamewallarray[TESTNUMWALLS] = {{-544.0f,0.0f,512.0f,0.0f},	// Bottom strip
					       {-512.0f,64.0f,448.0f,64.0f},
					       {512.0f,0.0f,576.0f,64.0f},	// Corner
					       {448.0f,64.0f,512.0f,128.0f},
					       {512.0f,128.0f,512.0f,576.0f},	// Upwards strip
					       {576.0f,64.0f,576.0f,576.0f},
					       {576.0f,576.0f,512.0f,640.0f},	// Top corner
					       {512.0f,576.0f,448.0f,576.0f},
					       {512.0f,640.0f,403.0f,640.0f},
					       {448.0f,576.0f,64.0f,192.0f},	// Diagonal strip
					       {19.0f,256.0f,403.0f,640.0f},
					       {64.0f,192.0f,-512.0f,192.0f},	// Back strip
					       {-544.0f,256.0f,19.0f,256.0f},
					       {-608.0f,192.0f,-544.0f,256.0f},	// Last corner
					       {-608.0f,64.0f,-544.0f,0.0f},
					       {-608.0f,192.0f,-608.0f,64.0f},
					       {-512.0f,192.0f,-544.0f,160.0f},
					       {-512.0f,64.0f,-544.0f,96.0f},
					       {-544.0f,160.0f,-544.0f,96.0f}};

struct Walls testgamewalls = {TESTNUMWALLS,testgamewallarray};

// Guidelines

#define TESTNUMLINES 10

struct Guideline_c testlinearray_c[TESTNUMLINES] = {{-528.0f,32.0f,448.0f,32.0f},	// Bottom strip
						    {448.0f,32.0f,544.0f,128.0f},	// Corner
						    {544.0f,96.0f,544.0f,576.0f},	// Upwards strip
						    {544.0f,576.0f,512.0f,608.0f},	// Top corner
						    {512.0f,608.0f,425.5f,608.0f},
						    {425.5f,608.0f,41.5,224.0f},	// Diagonal strip
						    {41.5,224.0f,-528.0f,224.0f},	// Back strip
						    {-528.0f,224.0f,-576.0f,176.0f},	// Last corner
						    {-576.0f,176.0f,-576.0f,80.0f},
						    {-576.0f,80.0f,-528.0f,32.0f}};

struct Guidelines_c testconstructlines = {TESTNUMLINES,testlinearray_c};

struct Guideline testlinearray[TESTNUMLINES];
struct Guidelines testgamelines = {TESTNUMLINES,testlinearray};

void settestgame(void) {	
	// Guidelines
	constructguidelines(&testconstructlines,&testgamelines);
}
/*
struct Game testgame = {0.0f,0.0f,0.0f,0.9f,
			&settestgame,testaiplayers + TESTNUMAIPLAYERS,&backmesh,&testgamewalls,
			TESTNUMAIPLAYERS,testaiplayers,&testgamelines,
			1,{0.0f,0.0f,0.0f,64.0f}};
*/
//struct Game testgame;

void testgamefunc(void) {
	testaiplayers[0].x = -16.0f;	testaiplayers[0].z = 16.0f;	testaiplayers[0].vx = 0.0f;	testaiplayers[0].vz = 0.0f;	testaiplayers[0].angle = 270.0;	testaiplayers[0].anglespeed = 0.0;	testaiplayers[0].laps = 0;
	testaiplayers[1].x = -24.0f;	testaiplayers[1].z = 48.0f;	testaiplayers[1].vx = 0.0f;	testaiplayers[1].vz = 0.0f;	testaiplayers[1].angle = 270.0;	testaiplayers[1].anglespeed = 0.0;	testaiplayers[1].laps = 0;
	testaiplayers[2].x = -48.0f;	testaiplayers[2].z = 16.0f;	testaiplayers[2].vx = 0.0f;	testaiplayers[2].vz = 0.0f;	testaiplayers[2].angle = 270.0;	testaiplayers[2].anglespeed = 0.0;	testaiplayers[2].laps = 0;
	testaiplayers[3].x = -56.0f;	testaiplayers[3].z = 48.0f;	testaiplayers[3].vx = 0.0f;	testaiplayers[3].vz = 0.0f;	testaiplayers[3].angle = 270.0;	testaiplayers[3].anglespeed = 0.0;	testaiplayers[3].laps = 0;
	testaiplayers[4].x = -80.0f;	testaiplayers[4].z = 32.0f;	testaiplayers[4].vx = 0.0f;	testaiplayers[4].vz = 0.0f;	testaiplayers[4].angle = 270.0;	testaiplayers[4].anglespeed = 0.0;	testaiplayers[4].laps = 0;

	//testgame = (struct Game){0.0f,0.0f,0.0f,0.9f,
	//			 &settestgame,testaiplayers + TESTNUMAIPLAYERS,&backmesh,&testgamewalls,
	//			 TESTNUMAIPLAYERS,testaiplayers,&testgamelines,
	//			 1,(struct Wall){0.0f,0.0f,0.0f,64.0f}};
	//return &testgame;
}

struct Game testgame = {0.0f,0.0f,0.0f,0.9f,
			&settestgame,testaiplayers + TESTNUMAIPLAYERS,&backmesh,&noscene,&testgamewalls,
			TESTNUMAIPLAYERS,testaiplayers,&testgamelines,
			1,{0.0f,0.0f,0.0f,64.0f},&testgamefunc};
