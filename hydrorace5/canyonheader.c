#define CANYONGAMESTATS {0.22f,0.02f,0.75,0.75,0.75,8.0f}

// Players

#define CANYONNUMAIPLAYERS 4

struct Plane canyonaiplayers[CANYONNUMAIPLAYERS + 1] = {{&racemesh,-16.0f,16.0f,0.0f,0.0f,270.0,0.0,CANYONGAMESTATS,&blueiconmesh,0},
							{&racemesh,-24.0f,48.0f,0.0f,0.0f,270.0,0.0,CANYONGAMESTATS,&blueiconmesh,0},
							{&racemesh,-48.0f,16.0f,0.0f,0.0f,270.0,0.0,CANYONGAMESTATS,&blueiconmesh,0},
							{&racemesh,-56.0f,48.0f,0.0f,0.0f,270.0,0.0,CANYONGAMESTATS,&blueiconmesh,0},
							{&racemesh,-80.0f,32.0f,0.0f,0.0f,270.0,0.0,CANYONGAMESTATS,&rediconmesh,0}};

// Walls

#define CANYONNUMWALLS 30

struct Wall canyongamewallarray[CANYONNUMWALLS] = {{288.0f,0.0f,-192.0f,0.0f},	// Home
						   {256.0f,64.0f,-256.0f,64.0f},
						   {288.0f,0.0f,832.0f,544.0f},	// Diag
						   {256.0f,64.0f,768.0f,576.0f},
						   {832.0f,608.0f,832.0f,544.0f},	// C1
						   {800.0f,640.0f,832.0f,608.0f},
						   {768.0f,576.0f,736.0f,608.0f},
						   {736.0f,672.0f,800.0f,640.0f},
						   {736.0f,608.0f,480.0f,608.0f},	// Split lead
						   {736.0f,672.0f,480.0f,672.0f},
						   {362.0f,640.0f,234.0f,672.0f},	// Split centre
						   {362.0f,640.0f,234.0f,608.0f},
						   {106.0f,640.0f,234.0f,672.0f},
						   {106.0f,640.0f,234.0f,608.0f},
						   {480.0f,672.0f,234.0f,736.0f},	// Split edges
						   {480.0f,608.0f,234.0f,544.0f},
						   {-22.0f,672.0f,234.0f,736.0f},
						   {-22.0f,608.0f,234.0f,544.0f},
						   {-22.0f,608.0f,-320.0f,608.0f},	// Split end
						   {-22.0f,672.0f,-384.0f,672.0f},
						   {-320.0f,608.0f,-320.0f,0.0f},	// D1
						   {-384.0f,64.0f,-384.0f,672.0f},
						   {-320.0f,0.0f,-384.0f,0.0f},	// Chic
						   {-384.0f,64.0f,-448.0f,64.0f},
						   {-384.0f,0.0f,-384.0f,-64.0f},	// D2
						   {-448.0f,-128.0f,-448.0f,64.0f},
						   {-192.0f,-128.0f,-448.0f,-128.0f},	// C3
						   {-384.0f,-64.0f,-256.0f,-64.0f},
						   {-192.0f,0.0f,-192.0f,-128.0f},	// Last
						   {-256.0f,-64.0f,-256.0f,64.0f}};
struct Walls canyongamewalls = {CANYONNUMWALLS,canyongamewallarray};

// Guidelines

#define CANYONNUMLINES 16

struct Guideline_c canyonlinearray_c[CANYONNUMLINES] = {{-160.0f,32.0f,272.0f,56.0f},	// Home
							{272.0f,56.0f,800.0f,560.0f},	// Diag
							{800.0f,560.0f,784.0f,608.0f},	// C1
							{784.0f,608.0f,736.0f,640.0f},
							{736.0f,640.0f,480.0f,640.0f},	// Split lead
							{480.0f,640.0f,234.0f,688.0f},	// Split centre
							{480.0f,640.0f,234.0f,592.0f},
							{234.0f,688.0f,-22.0f,640.0f},
							{234.0f,592.0f,-22.0f,640.0f},
							{-22.0f,640.0f,-288.0f,640.0f},	// Split end
							{-288.0f,640.0f,-352.0f,576.0f},	// C2
							{-352.0f,576.0f,-368.0f,64.0f},	// D1
							{-368.0f,64.0f,-416.0f,-32.0f},	// Chic
							{-416.0f,-32.0f,-352.0f,-96.0f},	// C3
							{-352.0f,-96.0f,-288.0f,-96.0f},
							{-288.0f,-96.0f,-160.0f,32.0f}};	// Last

struct Guidelines_c canyonconstructlines = {CANYONNUMLINES,canyonlinearray_c};

struct Guideline canyonlinearray[CANYONNUMLINES];
struct Guidelines canyongamelines = {CANYONNUMLINES,canyonlinearray};

void setcanyongame(void) {
	// Guidelines
	constructguidelines(&canyonconstructlines,&canyongamelines);
}

void canyongamefunc(void) {
	canyonaiplayers[0].x = -16.0f;	canyonaiplayers[0].z = 16.0f;	canyonaiplayers[0].vx = 0.0f;	canyonaiplayers[0].vz = 0.0f;	canyonaiplayers[0].angle = 270.0;	canyonaiplayers[0].anglespeed = 0.0;	canyonaiplayers[0].laps = 0;
	canyonaiplayers[1].x = -24.0f;	canyonaiplayers[1].z = 48.0f;	canyonaiplayers[1].vx = 0.0f;	canyonaiplayers[1].vz = 0.0f;	canyonaiplayers[1].angle = 270.0;	canyonaiplayers[1].anglespeed = 0.0;	canyonaiplayers[1].laps = 0;
	canyonaiplayers[2].x = -48.0f;	canyonaiplayers[2].z = 16.0f;	canyonaiplayers[2].vx = 0.0f;	canyonaiplayers[2].vz = 0.0f;	canyonaiplayers[2].angle = 270.0;	canyonaiplayers[2].anglespeed = 0.0;	canyonaiplayers[2].laps = 0;
	canyonaiplayers[3].x = -56.0f;	canyonaiplayers[3].z = 48.0f;	canyonaiplayers[3].vx = 0.0f;	canyonaiplayers[3].vz = 0.0f;	canyonaiplayers[3].angle = 270.0;	canyonaiplayers[3].anglespeed = 0.0;	canyonaiplayers[3].laps = 0;
	canyonaiplayers[4].x = -80.0f;	canyonaiplayers[4].z = 32.0f;	canyonaiplayers[4].vx = 0.0f;	canyonaiplayers[4].vz = 0.0f;	canyonaiplayers[4].angle = 270.0;	canyonaiplayers[4].anglespeed = 0.0;	canyonaiplayers[4].laps = 0;
}

struct Game canyongame = {0.0f,0.0f,0.0f,0.9f,
			  &setcanyongame,canyonaiplayers + CANYONNUMAIPLAYERS,&canyonmesh,&canyonscenemesh,&canyongamewalls,
			  CANYONNUMAIPLAYERS,canyonaiplayers,&canyongamelines,
			  3,{0.0f,0.0f,0.0f,64.0f},&canyongamefunc};
