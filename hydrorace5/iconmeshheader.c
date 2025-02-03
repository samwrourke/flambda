#define ICONTRIANGLES 2

GLfloat iconvertices[ICONTRIANGLES * 3 * 3] = {0.0f,0.0f,-15.0f,	30.0f,0.0f,-30.0f,	0.0f,0.0f,30.0f,	
					       0.0f,0.0f,30.0f,	-30.0f,0.0f,-30.0f,	0.0f,0.0f,-15.0f};
GLfloat blueiconcolours[ICONTRIANGLES * 3 * 4] = {BLUE,BLUE,BLUE,BLUE,BLUE,BLUE};
GLfloat rediconcolours[ICONTRIANGLES * 3 * 4] = {RED,RED,RED,RED,RED,RED};
struct Mesh blueiconmesh = {NULL,ICONTRIANGLES * 3,iconvertices,blueiconcolours};
struct Mesh rediconmesh = {NULL,ICONTRIANGLES * 3,iconvertices,rediconcolours};