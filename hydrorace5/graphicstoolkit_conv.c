#include "../showroom/allcolours.c"

#define TWOPIOVERTHREE M_PI * 2 / 3

struct Mesh {
	GLfloat *matrix;
	int numvertices;
	GLfloat *vertices;
	GLfloat *colours;
};

void drawmesh(struct Mesh *mesh) {
	glVertexPointer(3,GL_FLOAT,0,mesh->vertices);
	glColorPointer(4,GL_FLOAT,0,mesh->colours);
	
	glPushMatrix();
	glMultMatrixf(mesh->matrix);
	
	glDrawArrays(GL_TRIANGLES,0,mesh->numvertices);
	
	glPopMatrix();
}

void drawmesh_nomat(struct Mesh *mesh) {
	glVertexPointer(3,GL_FLOAT,0,mesh->vertices);
	glColorPointer(4,GL_FLOAT,0,mesh->colours);
	
	glDrawArrays(GL_TRIANGLES,0,mesh->numvertices);
}

void addtriangle_normal(struct Mesh *mesh,int *n,
			GLfloat x0,GLfloat y0,GLfloat z0,
			GLfloat x1,GLfloat y1,GLfloat z1,
			GLfloat x2,GLfloat y2,GLfloat z2,
			GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
			GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
			GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	if ((((*n) + 1) * 3) > mesh->numvertices || (*n) < 0) {
		fprintf(stderr,"Bad value of n\n");
	}
	else {
		int vertexpos = (*n) * 3 * 3;
		int colourpos = (*n) * 3 * 4;
		mesh->vertices[vertexpos] = x0;	mesh->vertices[vertexpos + 1] = y0;	mesh->vertices[vertexpos + 2] = z0;
		mesh->vertices[vertexpos + 3] = x1;	mesh->vertices[vertexpos + 4] = y1;	mesh->vertices[vertexpos + 5] = z1;
		mesh->vertices[vertexpos + 6] = x2;	mesh->vertices[vertexpos + 7] = y2;	mesh->vertices[vertexpos + 8] = z2;
		mesh->colours[colourpos] = r0;	mesh->colours[colourpos + 1] = g0;	mesh->colours[colourpos + 2] = b0;	mesh->colours[colourpos + 3] = a0;
		mesh->colours[colourpos + 4] = r1;	mesh->colours[colourpos + 5] = g1;	mesh->colours[colourpos + 6] = b1;	mesh->colours[colourpos + 7] = a1;
		mesh->colours[colourpos + 8] = r2;	mesh->colours[colourpos + 9] = g2;	mesh->colours[colourpos + 10] = b2;	mesh->colours[colourpos + 11] = a2;
	}
	(*n)++;
}

void addtriangle_invert(struct Mesh *mesh,int *n,
			GLfloat x0,GLfloat y0,GLfloat z0,
			GLfloat x1,GLfloat y1,GLfloat z1,
			GLfloat x2,GLfloat y2,GLfloat z2,
			GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
			GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
			GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	if ((((*n) + 1) * 3) > mesh->numvertices || (*n) < 0) {
		fprintf(stderr,"Bad value of n\n");
	}
	else {
		int vertexpos = (*n) * 3 * 3;
		int colourpos = (*n) * 3 * 4;
		mesh->vertices[vertexpos] = x0;	mesh->vertices[vertexpos + 1] = y0;	mesh->vertices[vertexpos + 2] = z0;
		mesh->vertices[vertexpos + 3] = x2;	mesh->vertices[vertexpos + 4] = y2;	mesh->vertices[vertexpos + 5] = z2;
		mesh->vertices[vertexpos + 6] = x1;	mesh->vertices[vertexpos + 7] = y1;	mesh->vertices[vertexpos + 8] = z1;
		mesh->colours[colourpos] = r0;	mesh->colours[colourpos + 1] = g0;	mesh->colours[colourpos + 2] = b0;	mesh->colours[colourpos + 3] = a0;
		mesh->colours[colourpos + 4] = r2;	mesh->colours[colourpos + 5] = g2;	mesh->colours[colourpos + 6] = b2;	mesh->colours[colourpos + 7] = a2;
		mesh->colours[colourpos + 8] = r1;	mesh->colours[colourpos + 9] = g1;	mesh->colours[colourpos + 10] = b1;	mesh->colours[colourpos + 11] = a1;
	}
	(*n)++;
}

#define addtriangle addtriangle_invert

void addtriangle_bothsides(struct Mesh *mesh,int *n,
			   GLfloat x0,GLfloat y0,GLfloat z0,
			   GLfloat x1,GLfloat y1,GLfloat z1,
			   GLfloat x2,GLfloat y2,GLfloat z2,
			   GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
			   GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
			   GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	addtriangle(mesh,n,
		    x0,y0,z0,
		    x1,y1,z1,
		    x2,y2,z2,
		    r0,g0,b0,a0,
		    r1,g1,b1,a1,
		    r2,g2,b2,a2);
	addtriangle(mesh,n,
		    x0,y0,z0,
		    x2,y2,z2,
		    x1,y1,z1,
		    r0,g0,b0,a0,
		    r2,g2,b2,a2,
		    r1,g1,b1,a1);
}

void addtriangle_diffsides(struct Mesh *mesh,int *n,
			   GLfloat x0,GLfloat y0,GLfloat z0,
			   GLfloat x1,GLfloat y1,GLfloat z1,
			   GLfloat x2,GLfloat y2,GLfloat z2,
			   GLfloat r0_a,GLfloat g0_a,GLfloat b0_a,GLfloat a0_a,
			   GLfloat r1_a,GLfloat g1_a,GLfloat b1_a,GLfloat a1_a,
			   GLfloat r2_a,GLfloat g2_a,GLfloat b2_a,GLfloat a2_a,
			   GLfloat r0_b,GLfloat g0_b,GLfloat b0_b,GLfloat a0_b,
			   GLfloat r1_b,GLfloat g1_b,GLfloat b1_b,GLfloat a1_b,
			   GLfloat r2_b,GLfloat g2_b,GLfloat b2_b,GLfloat a2_b) {
	addtriangle(mesh,n,
		    x0,y0,z0,
		    x1,y1,z1,
		    x2,y2,z2,
		    r0_a,g0_a,b0_a,a0_a,
		    r1_a,g1_a,b1_a,a1_a,
		    r2_a,g2_a,b2_a,a2_a);
	addtriangle(mesh,n,
		    x0,y0,z0,
		    x2,y2,z2,
		    x1,y1,z1,
		    r0_b,g0_b,b0_b,a0_b,
		    r2_b,g2_b,b2_b,a2_b,
		    r1_b,g1_b,b1_b,a1_b);
}

void addtriangle_mono(struct Mesh *mesh,int *n,
		      GLfloat x0,GLfloat y0,GLfloat z0,
		      GLfloat x1,GLfloat y1,GLfloat z1,
		      GLfloat x2,GLfloat y2,GLfloat z2,
		      GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addtriangle(mesh,n,
		    x0,y0,z0,
		    x1,y1,z1,
		    x2,y2,z2,
		    r,g,b,a,
		    r,g,b,a,
		    r,g,b,a);
}

void addtriangle_bothsides_mono(struct Mesh *mesh,int *n,
				GLfloat x0,GLfloat y0,GLfloat z0,
				GLfloat x1,GLfloat y1,GLfloat z1,
				GLfloat x2,GLfloat y2,GLfloat z2,
				GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addtriangle_bothsides(mesh,n,
			      x0,y0,z0,
			      x1,y1,z1,
			      x2,y2,z2,
			      r,g,b,a,
			      r,g,b,a,
			      r,g,b,a);
}

void addtriangle_diffsides_mono(struct Mesh *mesh,int *n,
				GLfloat x0,GLfloat y0,GLfloat z0,
				GLfloat x1,GLfloat y1,GLfloat z1,
				GLfloat x2,GLfloat y2,GLfloat z2,
				GLfloat r_a,GLfloat g_a,GLfloat b_a,GLfloat a_a,
				GLfloat r_b,GLfloat g_b,GLfloat b_b,GLfloat a_b) {
	addtriangle_diffsides(mesh,n,
			      x0,y0,z0,
			      x1,y1,z1,
			      x2,y2,z2,
			      r_a,g_a,b_a,a_a,
			      r_a,g_a,b_a,a_a,
			      r_a,g_a,b_a,a_a,
			      r_b,g_b,b_b,a_b,
			      r_b,g_b,b_b,a_b,
			      r_b,g_b,b_b,a_b);
}

void addtriangle_reflect(struct Mesh *mesh,int *n,int reflectx,int reflecty,int reflectz,
			 GLfloat x0,GLfloat y0,GLfloat z0,
			 GLfloat x1,GLfloat y1,GLfloat z1,
			 GLfloat x2,GLfloat y2,GLfloat z2,
			 GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
			 GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
			 GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	if (reflectx) {
		if (reflecty) {
			if (reflectz) {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,y0,-z0,x2,y2,-z2,x1,y1,-z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,x0,-y0,z0,x2,-y2,z2,x1,-y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,x0,-y0,-z0,x1,-y1,-z1,x2,-y2,-z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,-x0,y0,z0,-x2,y2,z2,-x1,y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,-x0,y0,-z0,-x1,y1,-z1,-x2,y2,-z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,-x0,-y0,z0,-x1,-y1,z1,-x2,-y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,-x0,-y0,-z0,-x2,-y2,-z2,-x1,-y1,-z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
			}
			else {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,-y0,z0,x2,-y2,z2,x1,-y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,-x0,y0,z0,-x2,y2,z2,-x1,y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,-x0,-y0,z0,-x1,-y1,z1,-x2,-y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
			}
		}
		else {
			if (reflectz) {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,y0,-z0,x2,y2,-z2,x1,y1,-z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,-x0,y0,z0,-x2,y2,z2,-x1,y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,-x0,y0,-z0,-x1,y1,-z1,-x2,y2,-z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
			}
			else {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,-x0,y0,z0,-x2,y2,z2,-x1,y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
			}
		}
	}
	else {
		if (reflecty) {
			if (reflectz) {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,y0,-z0,x2,y2,-z2,x1,y1,-z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,x0,-y0,z0,x2,-y2,z2,x1,-y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
				addtriangle(mesh,n,x0,-y0,-z0,x1,-y1,-z1,x2,-y2,-z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
			}
			else {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,-y0,z0,x2,-y2,z2,x1,-y1,z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
			}
		}
		else {
			if (reflectz) {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
				addtriangle(mesh,n,x0,y0,-z0,x2,y2,-z2,x1,y1,-z1,r0,g0,b0,a0,r2,g2,b2,a2,r1,g1,b1,a1);
			}
			else {
				addtriangle(mesh,n,x0,y0,z0,x1,y1,z1,x2,y2,z2,r0,g0,b0,a0,r1,g1,b1,a1,r2,g2,b2,a2);
			}
		}
	}
}

void addtriangle_bothsides_reflect(struct Mesh *mesh,int *n,int relflectx,int relflecty,int relflectz,
				   GLfloat x0,GLfloat y0,GLfloat z0,
				   GLfloat x1,GLfloat y1,GLfloat z1,
				   GLfloat x2,GLfloat y2,GLfloat z2,
				   GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
				   GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
				   GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	addtriangle_reflect(mesh,n,relflectx,relflecty,relflectz,
			    x0,y0,z0,
			    x1,y1,z1,
			    x2,y2,z2,
			    r0,g0,b0,a0,
			    r1,g1,b1,a1,
			    r2,g2,b2,a2);
	addtriangle_reflect(mesh,n,relflectx,relflecty,relflectz,
			    x0,y0,z0,
			    x2,y2,z2,
			    x1,y1,z1,
			    r0,g0,b0,a0,
			    r2,g2,b2,a2,
			    r1,g1,b1,a1);
}

void addtriangle_diffsides_reflect(struct Mesh *mesh,int *n,int relflectx,int relflecty,int relflectz,
				   GLfloat x0,GLfloat y0,GLfloat z0,
				   GLfloat x1,GLfloat y1,GLfloat z1,
				   GLfloat x2,GLfloat y2,GLfloat z2,
				   GLfloat r0_a,GLfloat g0_a,GLfloat b0_a,GLfloat a0_a,
				   GLfloat r1_a,GLfloat g1_a,GLfloat b1_a,GLfloat a1_a,
				   GLfloat r2_a,GLfloat g2_a,GLfloat b2_a,GLfloat a2_a,
				   GLfloat r0_b,GLfloat g0_b,GLfloat b0_b,GLfloat a0_b,
				   GLfloat r1_b,GLfloat g1_b,GLfloat b1_b,GLfloat a1_b,
				   GLfloat r2_b,GLfloat g2_b,GLfloat b2_b,GLfloat a2_b) {
	addtriangle_reflect(mesh,n,relflectx,relflecty,relflectz,
			    x0,y0,z0,
			    x1,y1,z1,
			    x2,y2,z2,
			    r0_a,g0_a,b0_a,a0_a,
			    r1_a,g1_a,b1_a,a1_a,
			    r2_a,g2_a,b2_a,a2_a);
	addtriangle_reflect(mesh,n,relflectx,relflecty,relflectz,
			    x0,y0,z0,
			    x2,y2,z2,
			    x1,y1,z1,
			    r0_b,g0_b,b0_b,a0_b,
			    r2_b,g2_b,b2_b,a2_b,
			    r1_b,g1_b,b1_b,a1_b);
}

void addtriangle_mono_reflect(struct Mesh *mesh,int *n,int relflectx,int relflecty,int relflectz,
			      GLfloat x0,GLfloat y0,GLfloat z0,
			      GLfloat x1,GLfloat y1,GLfloat z1,
			      GLfloat x2,GLfloat y2,GLfloat z2,
			      GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addtriangle_reflect(mesh,n,relflectx,relflecty,relflectz,
			    x0,y0,z0,
			    x1,y1,z1,
			    x2,y2,z2,
			    r,g,b,a,
			    r,g,b,a,
			    r,g,b,a);
}

void addtriangle_bothsides_mono_reflect(struct Mesh *mesh,int *n,int relflectx,int relflecty,int relflectz,
					GLfloat x0,GLfloat y0,GLfloat z0,
					GLfloat x1,GLfloat y1,GLfloat z1,
					GLfloat x2,GLfloat y2,GLfloat z2,
					GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addtriangle_bothsides_reflect(mesh,n,relflectx,relflecty,relflectz,
				      x0,y0,z0,
				      x1,y1,z1,
				      x2,y2,z2,
				      r,g,b,a,
				      r,g,b,a,
				      r,g,b,a);
}

void addtriangle_diffsides_mono_reflect(struct Mesh *mesh,int *n,int relflectx,int relflecty,int relflectz,
					GLfloat x0,GLfloat y0,GLfloat z0,
					GLfloat x1,GLfloat y1,GLfloat z1,
					GLfloat x2,GLfloat y2,GLfloat z2,
					GLfloat r_a,GLfloat g_a,GLfloat b_a,GLfloat a_a,
					GLfloat r_b,GLfloat g_b,GLfloat b_b,GLfloat a_b) {
	addtriangle_diffsides_reflect(mesh,n,relflectx,relflecty,relflectz,
				      x0,y0,z0,
				      x1,y1,z1,
				      x2,y2,z2,
				      r_a,g_a,b_a,a_a,
				      r_a,g_a,b_a,a_a,
				      r_a,g_a,b_a,a_a,
				      r_b,g_b,b_b,a_b,
				      r_b,g_b,b_b,a_b,
				      r_b,g_b,b_b,a_b);
}

void gencirlepoints(char axis,int ntris,double angadd,
		    GLfloat x,GLfloat y,GLfloat z,
		    GLfloat *vertexarray) {
	int nvs = abs(ntris * 3);
	int i;	
	double angle;
	double angleconst = TWOPIOVERTHREE / ntris;
	double angleadd = angadd * angleconst * 3;
	double sinangle;
	double cosangle;

	switch (axis) {
		case 'x':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * angleconst) + angleadd;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = x;
				vertexarray[i + 1] = (y * sinangle) + (z * cosangle);
				vertexarray[i + 2] = (y * cosangle) + (z * sinangle);
			}
			break;
		case 'y':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * angleconst) + angleadd;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = (x * cosangle) + (z * sinangle);
				vertexarray[i + 1] = y;
				vertexarray[i + 2] = (x * sinangle) + (z * cosangle);
			}
			break;
		case 'z':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * angleconst) + angleadd;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = (x * sinangle) + (y * cosangle);
				vertexarray[i + 1] = (x * cosangle) - (y * sinangle);
				vertexarray[i + 2] = z;
			}
			break;
		default:
			fprintf(stderr,"Axis must be x, y or z");
	}
}

void gencirclepoints_range(char axis,int nangs,double angstart,double angstep,
			   GLfloat x,GLfloat y,GLfloat z,
			   GLfloat *vertexarray) {
	int nvs = abs(nangs * 3);
	int i;	
	double angle;
	double anglestep = angstep / 3.0;
	double sinangle;
	double cosangle;
	switch (axis) {
		case 'x':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * anglestep) + angstart;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = x;
				vertexarray[i + 1] = (y * sinangle) + (z * cosangle);
				vertexarray[i + 2] = (y * cosangle) + (z * sinangle);
			}
			break;
		case 'y':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * anglestep) + angstart;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = (x * cosangle) + (z * sinangle);
				vertexarray[i + 1] = y;
				vertexarray[i + 2] = (x * sinangle) + (z * cosangle);
			}
			break;
		case 'z':
			for (i = 0; i < nvs; i += 3) {
				angle = (i * anglestep) + angstart;
				sinangle = sin(angle);
				cosangle = cos(angle);
				vertexarray[i] = (x * sinangle) + (y * cosangle);
				vertexarray[i + 1] = (x * cosangle) - (y * sinangle);
				vertexarray[i + 2] = z;
			}
			break;
		default:
			fprintf(stderr,"Axis must be x, y or z");
	}
}

void addhalffustrum(struct Mesh *mesh,int *n,
		    char axis,GLfloat radb,GLfloat rade,GLfloat l,int ntris,double angadd,
		    GLfloat x,GLfloat y,GLfloat z,
		    GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		    GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
		    GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	int nvs = abs(ntris * 3);
	GLfloat basevertices[nvs];
	GLfloat endvertices[nvs];
	
	switch (axis) {
		case 'x':
			gencirlepoints('x',ntris,angadd,
				       0.0f,radb,0.0f,
				       basevertices);
			gencirlepoints('x',ntris,angadd + 0.5f,
				       l,rade,0.0f,
				       endvertices);
			break;
		case 'y':
			gencirlepoints('y',ntris,angadd,
				       radb,0.0f,0.0f,
				       basevertices);
			gencirlepoints('y',ntris,angadd + 0.5f,
				       rade,l,0.0f,
				       endvertices);
			break;
		case 'z':
			gencirlepoints('z',ntris,angadd,
				       radb,0.0f,0.0f,
				       basevertices);
			gencirlepoints('z',ntris,angadd + 0.5f,
				       rade,0.0f,l,
				       endvertices);
			break;
		default:
			fprintf(stderr,"Axis must be x, y or z");
			return;
	}

	int i;
	int ni;
	for (i = 0; i < nvs; i += 3) {
		ni = (i + 3) % nvs;
		addtriangle(mesh,n,
			    basevertices[i] + x,basevertices[i + 1] + y,basevertices[i + 2] + z,
			    endvertices[i] + x,endvertices[i + 1] + y,endvertices[i + 2] + z,
			    basevertices[ni] + x,basevertices[ni + 1] + y,basevertices[ni + 2] + z,
			    r0,g0,b0,a0,
			    r1,g1,b1,a1,
			    r2,g2,b2,a2);
	}
}

void addcone(struct Mesh *mesh,int *n,
	     char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
	     GLfloat x,GLfloat y,GLfloat z,
	     GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
	     GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
	     GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	addhalffustrum(mesh,n,
		       axis,rad,0.0f,l,ntris,angadd,
		       x,y,z,
		       r0,g0,b0,a0,
		       r1,g1,b1,a1,
		       r2,g2,b2,a2);
}

void addcone_grad(struct Mesh *mesh,int *n,
		  char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		  GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	addcone(mesh,n,
		axis,rad,l,ntris,angadd,
		x,y,z,
		r0,g0,b0,a0,
		r1,g1,b1,a1,
		r0,g0,b0,a0);
}

void addcone_mono(struct Mesh *mesh,int *n,
		  char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addcone(mesh,n,
		axis,rad,l,ntris,angadd,
		x,y,z,
		r,g,b,a,
		r,g,b,a,
		r,g,b,a);
}

void adddisc(struct Mesh *mesh,int *n,
	     char axis,GLfloat rad,int ntris,double angadd,
	     GLfloat x,GLfloat y,GLfloat z,
	     GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
	     GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
	     GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2) {
	addcone(mesh,n,
		axis,rad,0.0f,ntris,angadd,
		x,y,z,
		r0,g0,b0,a0,
		r1,g1,b1,a1,
		r2,g2,b2,a2);
}

void adddisc_grad(struct Mesh *mesh,int *n,
		  char axis,GLfloat rad,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		  GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	adddisc(mesh,n,
		axis,rad,ntris,angadd,
		x,y,z,
		r0,g0,b0,a0,
		r1,g1,b1,a1,
		r0,g0,b0,a0);
}

void adddisc_mono(struct Mesh *mesh,int *n,
		  char axis,GLfloat rad,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	adddisc(mesh,n,
		axis,rad,ntris,angadd,
		x,y,z,
		r,g,b,a,
		r,g,b,a,
		r,g,b,a);
}

void addfustrum(struct Mesh *mesh,int *n,
		char axis,GLfloat radb,GLfloat rade,GLfloat l,int ntris,double angadd,
		GLfloat x,GLfloat y,GLfloat z,
		GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
		GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2,
		GLfloat r3,GLfloat g3,GLfloat b3,GLfloat a3,
		GLfloat r4,GLfloat g4,GLfloat b4,GLfloat a4,
		GLfloat r5,GLfloat g5,GLfloat b5,GLfloat a5) {
	int nvs = abs(ntris * 3);
	GLfloat basevertices[nvs];
	GLfloat endvertices[nvs];
	
	switch (axis) {
		case 'x':
			gencirlepoints('x',ntris,angadd,
				       0.0f,radb,0.0f,
				       basevertices);
			gencirlepoints('x',ntris,angadd + 0.5f,
				       l,rade,0.0f,
				       endvertices);
			break;
		case 'y':
			gencirlepoints('y',ntris,angadd,
				       radb,0.0f,0.0f,
				       basevertices);
			gencirlepoints('y',ntris,angadd + 0.5f,
				       rade,l,0.0f,
				       endvertices);
			break;
		case 'z':
			gencirlepoints('z',ntris,angadd,
				       radb,0.0f,0.0f,
				       basevertices);
			gencirlepoints('z',ntris,angadd + 0.5f,
				       rade,0.0f,l,
				       endvertices);
			break;
		default:
			fprintf(stderr,"Axis must be x, y or z");
			return;
	}
	
	int i;
	int ni;
	for (i = 0; i < nvs; i += 3) {
		ni = (i + 3) % nvs;
		addtriangle(mesh,n,
			    basevertices[i] + x,basevertices[i + 1] + y,basevertices[i + 2] + z,
			    endvertices[i] + x,endvertices[i + 1] + y,endvertices[i + 2] + z,
			    basevertices[ni] + x,basevertices[ni + 1] + y,basevertices[ni + 2] + z,
			    r0,g0,b0,a0,
			    r1,g1,b1,a1,
			    r2,g2,b2,a2);
		addtriangle(mesh,n,
			    basevertices[ni] + x,basevertices[ni + 1] + y,basevertices[ni + 2] + z,
			    endvertices[i] + x,endvertices[i + 1] + y,endvertices[i + 2] + z,
			    endvertices[ni] + x,endvertices[ni + 1] + y,endvertices[ni + 2] + z,
			    r3,g3,b3,a3,
			    r4,g4,b4,a4,
			    r5,g5,b5,a5);
	}
}

void addfustrum_grad(struct Mesh *mesh,int *n,
		     char axis,GLfloat radb,GLfloat rade,GLfloat l,int ntris,double angadd,
		     GLfloat x,GLfloat y,GLfloat z,
		     GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		     GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	addfustrum(mesh,n,
		   axis,radb,rade,l,ntris,angadd,
		   x,y,z,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r0,g0,b0,a0,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r1,g1,b1,a1);
}		

void addfustrum_mono(struct Mesh *mesh,int *n,
		     char axis,GLfloat radb,GLfloat rade,GLfloat l,int ntris,double angadd,
		     GLfloat x,GLfloat y,GLfloat z,
		     GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addfustrum(mesh,n,
		   axis,radb,rade,l,ntris,angadd,
		   x,y,z,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a);
}		

void addcylinder(struct Mesh *mesh,int *n,
		 char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
		 GLfloat x,GLfloat y,GLfloat z,
		 GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		 GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
		 GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2,
		 GLfloat r3,GLfloat g3,GLfloat b3,GLfloat a3,
		 GLfloat r4,GLfloat g4,GLfloat b4,GLfloat a4,
		 GLfloat r5,GLfloat g5,GLfloat b5,GLfloat a5) {
	addfustrum(mesh,n,
		   axis,rad,rad,l,ntris,angadd,
		   x,y,z,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r2,g2,b2,a2,
		   r3,g3,b3,a3,
		   r4,g4,b4,a4,
		   r5,g5,b5,a5);
}

void addcylinder_grad(struct Mesh *mesh,int *n,
		      char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
		      GLfloat x,GLfloat y,GLfloat z,
		      GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		      GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	addfustrum(mesh,n,
		   axis,rad,rad,l,ntris,angadd,
		   x,y,z,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r0,g0,b0,a0,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r1,g1,b1,a1);
}

void addcylinder_mono(struct Mesh *mesh,int *n,
		      char axis,GLfloat rad,GLfloat l,int ntris,double angadd,
		      GLfloat x,GLfloat y,GLfloat z,
		      GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addfustrum(mesh,n,
		   axis,rad,rad,l,ntris,angadd,
		   x,y,z,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a);
}

void addring(struct Mesh *mesh,int *n,
	     char axis,GLfloat rado,GLfloat radi,int ntris,double angadd,
	     GLfloat x,GLfloat y,GLfloat z,
	     GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
	     GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1,
	     GLfloat r2,GLfloat g2,GLfloat b2,GLfloat a2,
	     GLfloat r3,GLfloat g3,GLfloat b3,GLfloat a3,
	     GLfloat r4,GLfloat g4,GLfloat b4,GLfloat a4,
	     GLfloat r5,GLfloat g5,GLfloat b5,GLfloat a5) {
	addfustrum(mesh,n,
		   axis,rado,radi,0.0f,ntris,angadd,
		   x,y,z,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r2,g2,b2,a2,
		   r3,g3,b3,a3,
		   r4,g4,b4,a4,
		   r5,g5,b5,a5);
}

void addring_grad(struct Mesh *mesh,int *n,
		  char axis,GLfloat rado,GLfloat radi,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r0,GLfloat g0,GLfloat b0,GLfloat a0,
		  GLfloat r1,GLfloat g1,GLfloat b1,GLfloat a1) {
	addfustrum(mesh,n,
		   axis,rado,radi,0.0f,ntris,angadd,
		   x,y,z,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r0,g0,b0,a0,
		   r0,g0,b0,a0,
		   r1,g1,b1,a1,
		   r1,g1,b1,a1);
}

void addring_mono(struct Mesh *mesh,int *n,
		  char axis,GLfloat rado,GLfloat radi,int ntris,double angadd,
		  GLfloat x,GLfloat y,GLfloat z,
		  GLfloat r,GLfloat g,GLfloat b,GLfloat a) {
	addfustrum(mesh,n,
		   axis,rado,radi,0.0f,ntris,angadd,
		   x,y,z,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a,
		   r,g,b,a);
}