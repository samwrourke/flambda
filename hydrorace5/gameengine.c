#define SMALLANGLE 1.0
#define MAXDIST 64.0f
#define DISTFACTOR 0.01
#define STRAIGHTRESULT 0.1
#define HYDROY 0.0f
#define ZROTCO 1.5
#define OBSZROTCO ZROTCO * -0.5
#define SPEEDSCALE 2.0f
#define SMALLADD 1.0f

#define HANDCONVERT(speed) ((speed) * (-60.0) + 135.0)

struct Planestats {
	GLfloat accel;
	GLfloat lindrag;
	double rotaccel;
	double rotdrag;
	GLfloat bounceloss;
	GLfloat radius;
};

struct Plane {
	struct Mesh *mesh;
	GLfloat x,z;
	GLfloat vx,vz;
	double angle;
	double anglespeed;
	struct Planestats stats;
	struct Mesh *icon;
	int laps;
};

struct Wall {
	GLfloat x_s,z_s;
	GLfloat x_e,z_e;
};

struct Walls {
	int numwalls;
	struct Wall *wallarray;
};

signed char hitwall(GLfloat x_s,GLfloat z_s,GLfloat x_e,GLfloat z_e,struct Wall *wall) {
	// First test for parallel lines
	if (((wall->x_s - wall->x_e) / (wall->z_s - wall->z_e)) == ((x_s - x_e) / (z_s - z_e))) {
		return 0;
	}
	// If not parallel, find point of intersection, testing for divide by zero errors.
	GLfloat tempx = wall->x_e - wall->x_s;
	if (!tempx) {
		GLfloat z = z_s + ((z_e - z_s) * ((wall->x_s - x_s) / (x_e - x_s)));
		return ((z > wall->z_e) == (z < wall->z_s)) && ((wall->x_e < x_s) == (wall->x_e > x_e));
	}
	GLfloat tempz = wall->z_e - wall->z_s;
	if (!tempz) {
		GLfloat x = x_s + ((x_e - x_s) * ((wall->z_s - z_s) / (z_e - z_s)));
		return ((x > wall->x_e) == (x < wall->x_s)) && ((wall->z_e < z_s) == (wall->z_e > z_e));
	}
	GLfloat t0 = (((x_s - wall->x_s) / tempx) - ((z_s - wall->z_s) / tempz)) / (((z_e - z_s) / tempz) - ((x_e - x_s) / tempx));
	tempx = x_e - x_s;
	if (!tempx) {
		GLfloat z = wall->z_s + ((wall->z_e - wall->z_s) * ((x_s - wall->x_s) / (wall->x_e - wall->x_s)));
		return ((z > z_e) == (z < z_s)) && ((x_e < wall->x_s) == (x_e > wall->x_e));
	}	
	tempz = z_e - z_s;
	if (!tempz) {
		GLfloat x = wall->x_s + ((wall->x_e - wall->x_s) * ((z_s - wall->z_s) / (wall->z_e - wall->z_s)));
		return ((x > x_e) == (x < x_s)) && ((z_e < wall->z_s) == (z_e > wall->z_e));
	}
	GLfloat t1 = (((wall->x_s - x_s) / tempx) - ((wall->z_s - z_s) / tempz)) / (((wall->z_e - wall->z_s) / tempz) - ((wall->x_e - wall->x_s) / tempx));
	return (t0 > 0.0f) && (t0 < 1.0f) && (t1 > 0.0f) && (t1 < 1.0f);
}

struct Wall * hitwalls(GLfloat x_s,GLfloat z_s,GLfloat x_e,GLfloat z_e,struct Walls *walls) {
	// Returns a pointer to first wall hit, NULL if no walls are hit
	signed char result;
	int i;
	for (i = 0; i < walls->numwalls; i++) {
		result = hitwall(x_s,z_s,x_e,z_e,&((walls->wallarray)[i]));
		if (result) {
			return &((walls->wallarray)[i]);
		}
	}
	return NULL;
}

struct Guideline_c {
	GLfloat x0,z0,x1,z1;
};

struct Guidelines_c {
	int numlines;
	struct Guideline_c *linearray;
};

struct Guideline {
	GLfloat x0,z0,x1,z1,nx,nz,orthx,orthz;
};

struct Guidelines {
	int numlines;
	struct Guideline *linearray;
};

void constructguidelines(struct Guidelines_c *lines,struct Guidelines *lines_u) {
	int i;
	GLfloat xdiff;
	GLfloat zdiff;
	GLfloat normby;
	for (i = 0; i < lines->numlines; i++) {
		((lines_u)->linearray + i)->x0 = ((lines->linearray) + i)->x0;
		((lines_u)->linearray + i)->z0 = ((lines->linearray) + i)->z0;
		((lines_u)->linearray + i)->x1 = ((lines->linearray) + i)->x1;
		((lines_u)->linearray + i)->z1 = ((lines->linearray) + i)->z1;
		xdiff = ((lines->linearray) + i)->x0 - ((lines->linearray) + i)->x1;
		zdiff = ((lines->linearray) + i)->z0 - ((lines->linearray) + i)->z1;
		normby = sqrt((xdiff * xdiff) + (zdiff * zdiff));
		((lines_u)->linearray + i)->nx = xdiff / normby;
		((lines_u)->linearray + i)->nz = zdiff / normby;
		((lines_u)->linearray + i)->orthx = ((lines_u)->linearray + i)->nz;
		((lines_u)->linearray + i)->orthz = -(((lines_u)->linearray + i)->nx);
	}	
}

GLfloat combineddistance(GLfloat x,GLfloat z,struct Guideline *guideline) {
	GLfloat relx0 = x - guideline->x0;
	GLfloat relx1 = x - guideline->x1;
	GLfloat relz0 = z - guideline->z0;
	GLfloat relz1 = z - guideline->z1;
	return (relx0 * relx0) + (relz0 * relz0) + (relx1 * relx1) + (relz1 * relz1);
}

GLfloat distancetoline(GLfloat x,GLfloat z,struct Guideline *guideline) {
	GLfloat xdiff = guideline->x1 - guideline->x0;
	GLfloat zdiff = guideline->z1 - guideline->z0;
	return ((zdiff * x) - (xdiff * z) + (guideline->x1 * guideline->z0) - (guideline->x0 * guideline->z1)) / sqrt((xdiff * xdiff) + (zdiff * zdiff));
}

signed char online(GLfloat x,GLfloat z,GLfloat dist,struct Guideline *guideline) {
	GLfloat onx = x + (dist * guideline->orthx);
	GLfloat onz = z + (dist * guideline->orthz);
	if (guideline->x0 == guideline->x1) {
		return (onz < guideline->z0) == (onz > guideline->z1);
	}
	else {
		return (onx < guideline->x0) == (onx > guideline->x1);
	}
		
}

void loadobsevermatrix(struct Plane *plane,GLfloat x,GLfloat y,GLfloat z) {
	glLoadIdentity();
	glTranslatef(-x,-y,-z);
	glRotatef(plane->anglespeed * OBSZROTCO,0.0f,0.0f,1.0f);
	glRotatef(plane->angle,0.0f,1.0f,0.0f);
	glTranslatef(-(plane->x),-HYDROY,-(plane->z));
}

void loadminmapmatrix(struct Plane *plane,GLfloat x,GLfloat y,GLfloat z) {
	glLoadIdentity();
	glRotatef(-90.0f,1.0f,0.0f,0.0f);
	glTranslatef(-x,-y,-z);
	glRotatef(plane->angle,0.0f,1.0f,0.0f);
	glTranslatef(-(plane->x),-HYDROY,-(plane->z));
}

void updateplane(struct Plane *plane,signed char accel,signed char rot,struct Walls *walls,int ais,struct Plane *aiplayerarray,struct Wall *finishline) {
	// Update rotation
	plane->anglespeed += rot * (plane->stats).rotaccel;
	plane->anglespeed *= (plane->stats).rotdrag;
	plane->angle += plane->anglespeed;

	// Update velocity	
	GLfloat speed = sqrtf((plane->vx * plane->vx) + (plane->vz * plane->vz));
	plane->vx += sinf(-degreestoradians(plane->angle)) * ((float) accel) * (plane->stats).accel / (speed + SMALLADD);
	plane->vz += cosf(-degreestoradians(plane->angle)) * ((float) accel) * (plane->stats).accel / (speed + SMALLADD);
	plane->vx -= plane->vx * (plane->stats).lindrag;
	plane->vz -= plane->vz * (plane->stats).lindrag;
	
	// Test for collison with walls
	struct Wall *wallptr = hitwalls(plane->x + plane->vx,plane->z + plane->vz,plane->x,plane->z,walls);
	while (wallptr != NULL) {
		reflectline(wallptr->x_s - wallptr->x_e,wallptr->z_s - wallptr->z_e,plane->vx,plane->vz,&(plane->vx),&(plane->vz));
		wallptr = hitwalls(plane->x + plane->vx,plane->z + plane->vz,plane->x,plane->z,walls);
		plane->vx *= (plane->stats).bounceloss;
		plane->vz *= (plane->stats).bounceloss;
	}
	
	// Collision with other planes
	int i;
	for (i = 0; i <= ais; i++) {
		if ((aiplayerarray + i) != plane) {
			GLfloat sumrad = (plane->stats).radius + ((aiplayerarray + i)->stats).radius;
			GLfloat xdiff = plane->x - (aiplayerarray + i)->x;
			GLfloat zdiff = plane->z - (aiplayerarray + i)->z;
			if ((sumrad * sumrad) > ((xdiff * xdiff) + (zdiff * zdiff))) {
				GLfloat tempx,tempz;
				reflectnormal(xdiff,zdiff,plane->vx - (aiplayerarray + i)->vx,plane->vz - (aiplayerarray + i)->vz,&tempx,&tempz);
				plane->vx += tempx * (plane->stats).bounceloss;
				plane->vz += tempz * (plane->stats).bounceloss;
				(aiplayerarray + i)->vx -= tempx * ((aiplayerarray + i)->stats).bounceloss;
				(aiplayerarray + i)->vz -= tempz * ((aiplayerarray + i)->stats).bounceloss;
				
				// Now test for wall collision again
				wallptr = hitwalls(plane->x + plane->vx,plane->z + plane->vz,plane->x,plane->z,walls);
				while (wallptr != NULL) {
					reflectline(wallptr->x_s - wallptr->x_e,wallptr->z_s - wallptr->z_e,plane->vx,plane->vz,&(plane->vx),&(plane->vz));
					wallptr = hitwalls(plane->x + plane->vx,plane->z + plane->vz,plane->x,plane->z,walls);
					plane->vx *= (plane->stats).bounceloss;
					plane->vz *= (plane->stats).bounceloss;
				}
			}
		}
	}
	
	// Test for crossing of the finish line
	plane->laps += hitwall(plane->x + plane->vx,plane->z + plane->vz,plane->x,plane->z,finishline);
	
	// Update position
	plane->x += plane->vx;
	plane->z += plane->vz;
}
	
void drawplane(struct Plane *plane) {
	// Draw mesh
	glPushMatrix();
	glTranslatef((plane->x),HYDROY,(plane->z));
	glRotatef(-(plane->angle),0.0f,1.0f,0.0f);
	glRotatef(plane->anglespeed * ZROTCO,0.0f,0.0f,1.0f);
	drawmesh_nomat(plane->mesh);
	glPopMatrix();
}

void drawicon(struct Plane *plane) {
	glPushMatrix();
	glTranslatef((plane->x),HYDROY,(plane->z));
	glRotatef(-(plane->angle),0.0f,1.0f,0.0f);
	glRotatef(plane->anglespeed * ZROTCO,0.0f,0.0f,1.0f);
	drawmesh_nomat(plane->icon);
	glPopMatrix();
}
/*
int scalelevel(struct Plane *plane) {
	GLfloat speedsqrd = (plane->vx * plane->vx) + (plane->vz * plane->vz);
	//return 1 << ((int) (speedsqrt * 1.5f));
	return 1 << (int) logf((speedsqrd * SPEEDSCALE) + 1.0f);
	//return 1 << ((int) (speedsqrd * 0.4f));
}*/

void aiplane(struct Plane *plane,struct Walls *walls,struct Guidelines *guidelines,int ais,struct Plane *aiplayerarray,struct Wall *finishline) {
	struct Guideline *choseline;
	GLfloat shortestdist = INFINITY;
	GLfloat tempdist;
	int i;
	for (i = 0; i < guidelines->numlines; i++) {
		tempdist = distancetoline(plane->x,plane->z,(guidelines->linearray) + i);
		if (fabs(tempdist) < fabs(shortestdist) && fabs(tempdist) < MAXDIST && online(plane->x,plane->z,tempdist,(guidelines->linearray) + i)) {
			shortestdist = tempdist;
			choseline = (guidelines->linearray) + i;
		}
	}
	if (isinf(shortestdist)) {
		GLfloat comparedist = INFINITY;
		for (i = 0; i < guidelines->numlines; i++) {
			tempdist = combineddistance(plane->x,plane->z,(guidelines->linearray) + i);
			if (tempdist < comparedist) {
				comparedist = tempdist;
				shortestdist = distancetoline(plane->x,plane->z,(guidelines->linearray) + i);
				choseline = (guidelines->linearray) + i;
			}
		}
	}
	double useangle = degreestoradians(plane->angle) - (shortestdist * DISTFACTOR);
	GLfloat result = ((choseline->nx * sinf(SMALLANGLE - useangle)) + (choseline->nz * cosf(SMALLANGLE - useangle))) - ((choseline->nx * sinf(-SMALLANGLE - useangle)) + (choseline->nz * cosf(-SMALLANGLE - useangle)));

	if (fabs(result) < STRAIGHTRESULT) {
		updateplane(plane,1,0,walls,ais,aiplayerarray,finishline);
	}
	else {
		updateplane(plane,1,(result > 0) ? 1 : -1,walls,ais,aiplayerarray,finishline);
	}
}

void displayspeed(struct Plane *plane,GLfloat x,GLfloat y,GLfloat z) {
	GLfloat speed = sqrtf((plane->vx * plane->vx) + (plane->vz * plane->vz));
	glLoadIdentity();
	glTranslatef(-x,-y,-z);
	glPushMatrix();
	glMultMatrixf(speedomesh.matrix);
	drawmesh_nomat(&speedomesh);
	glRotatef(HANDCONVERT(speed),0.0f,0.0f,1.0f);
	drawmesh_nomat(&handmesh);
	glPopMatrix();
}

struct Game {
	GLfloat backr,backg,backb,backa;
	void (*setupfunction)(void);
	struct Plane *player;
	struct Mesh *backmesh;
	struct Mesh *scenemesh;
	struct Walls *walls;
	int numaiplayers;
	struct Plane *aiplayers;
	struct Guidelines *lines;
	int laps;
	struct Wall finishline;
	void (*resetfunction)(void);
};