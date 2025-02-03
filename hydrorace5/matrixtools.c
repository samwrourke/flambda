#define degreestoradians(x) ((x) / 180.0 * M_PI)

#define identitymatrix_m {1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f}
#define scalematrix_m(x,y,z,w) {(x),0.0f,0.0f,0.0f,0.0f,(y),0.0f,0.0f,0.0f,0.0f,(z),0.0f,0.0f,0.0f,0.0f,(w)}
#define translatematrix_m(x,y,z) {1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,(x),(y),(z),1.0f}

void reflectline(GLfloat l_x,GLfloat l_z,GLfloat v_x,GLfloat v_z,GLfloat *r_x,GLfloat *r_z) {
	GLfloat coif = 2 * (((l_x * v_x) + (l_z * v_z)) / ((l_x * l_x) + (l_z * l_z)));
	(*r_x) = (l_x * coif) - v_x;
	(*r_z) = (l_z * coif) - v_z;
}

void reflectnormal(GLfloat n_x,GLfloat n_z,GLfloat v_x,GLfloat v_z,GLfloat *r_x,GLfloat *r_z) {
	GLfloat coif = 2 * (((n_x * v_x) + (n_z * v_z)) / ((n_x * n_x) + (n_z * n_z)));
	(*r_x) = v_x - (n_x * coif);
	(*r_z) = v_z - (n_z * coif);
}

void multmatrix(GLfloat *matrixa,GLfloat *matrixb,GLfloat *matrixc) {
	GLfloat tempmatrix[16];
	tempmatrix[0] = (matrixa[0] * matrixb[0]) + (matrixa[4] * matrixb[1]) + (matrixa[8] * matrixb[2]) + (matrixa[12] * matrixb[3]);
	tempmatrix[4] = (matrixa[0] * matrixb[4]) + (matrixa[4] * matrixb[5]) + (matrixa[8] * matrixb[6]) + (matrixa[12] * matrixb[7]);
	tempmatrix[8] = (matrixa[0] * matrixb[8]) + (matrixa[4] * matrixb[9]) + (matrixa[8] * matrixb[10]) + (matrixa[12] * matrixb[11]);
	tempmatrix[12] = (matrixa[0] * matrixb[12]) + (matrixa[4] * matrixb[13]) + (matrixa[8] * matrixb[14]) + (matrixa[12] * matrixb[15]);
	tempmatrix[1] = (matrixa[1] * matrixb[0]) + (matrixa[5] * matrixb[1]) + (matrixa[9] * matrixb[2]) + (matrixa[13] * matrixb[3]);
	tempmatrix[5] = (matrixa[1] * matrixb[4]) + (matrixa[5] * matrixb[5]) + (matrixa[9] * matrixb[6]) + (matrixa[13] * matrixb[7]);
	tempmatrix[9] = (matrixa[1] * matrixb[8]) + (matrixa[5] * matrixb[9]) + (matrixa[9] * matrixb[10]) + (matrixa[13] * matrixb[11]);
	tempmatrix[13] = (matrixa[1] * matrixb[12]) + (matrixa[5] * matrixb[13]) + (matrixa[9] * matrixb[14]) + (matrixa[13] * matrixb[15]);
	tempmatrix[2] = (matrixa[2] * matrixb[0]) + (matrixa[6] * matrixb[1]) + (matrixa[10] * matrixb[2]) + (matrixa[14] * matrixb[3]);
	tempmatrix[6] = (matrixa[2] * matrixb[4]) + (matrixa[6] * matrixb[5]) + (matrixa[10] * matrixb[6]) + (matrixa[14] * matrixb[7]);
	tempmatrix[10] = (matrixa[2] * matrixb[8]) + (matrixa[6] * matrixb[9]) + (matrixa[10] * matrixb[10]) + (matrixa[14] * matrixb[11]);
	tempmatrix[14] = (matrixa[2] * matrixb[12]) + (matrixa[6] * matrixb[13]) + (matrixa[10] * matrixb[14]) + (matrixa[14] * matrixb[15]);
	tempmatrix[3] = (matrixa[3] * matrixb[0]) + (matrixa[7] * matrixb[1]) + (matrixa[1] * matrixb[2]) + (matrixa[15] * matrixb[3]);
	tempmatrix[7] = (matrixa[3] * matrixb[4]) + (matrixa[7] * matrixb[5]) + (matrixa[11] * matrixb[6]) + (matrixa[15] * matrixb[7]);
	tempmatrix[11] = (matrixa[3] * matrixb[8]) + (matrixa[7] * matrixb[9]) + (matrixa[11] * matrixb[10]) + (matrixa[15] * matrixb[11]);
	tempmatrix[15] = (matrixa[3] * matrixb[12]) + (matrixa[7] * matrixb[13]) + (matrixa[11] * matrixb[14]) + (matrixa[15] * matrixb[15]);
	memcpy(matrixc,tempmatrix,16 * sizeof(GLfloat));
}

void transposematrix(GLfloat *matrixa,GLfloat *matrixb) {
	GLfloat tempmatrix[16];
	tempmatrix[0] = matrixa[0];	tempmatrix[4] = matrixa[1];	tempmatrix[8] = matrixa[2];	tempmatrix[12] = matrixa[3];
	tempmatrix[1] = matrixa[4];	tempmatrix[5] = matrixa[5];	tempmatrix[9] = matrixa[6];	tempmatrix[13] = matrixa[7];
	tempmatrix[2] = matrixa[8];	tempmatrix[6] = matrixa[9];	tempmatrix[10] = matrixa[10];	tempmatrix[14] = matrixa[11];
	tempmatrix[3] = matrixa[12];	tempmatrix[7] = matrixa[13];	tempmatrix[11] = matrixa[14];	tempmatrix[15] = matrixa[15];
	memcpy(matrixb,tempmatrix,16 * sizeof(GLfloat));
}

void inversetransform(GLfloat *matrixa,GLfloat *matrixb) {
	GLfloat tempmatrix[16];
	tempmatrix[0] = matrixa[0];	tempmatrix[4] = matrixa[1];	tempmatrix[8] = matrixa[2];	tempmatrix[12] = -((matrixa[0] * matrixa[12]) + (matrixa[1] * matrixa[13]) + (matrixa[2] * matrixa[14]));
	//tempmatrix[12] = -matrixa[12];
	//tempmatrix[12] = -((matrixa[0] * matrixa[12]) + (matrixa[1] * matrixa[13]) + (matrixa[2] * matrixa[14]));
	tempmatrix[1] = matrixa[4];	tempmatrix[5] = matrixa[5];	tempmatrix[9] = matrixa[6];	tempmatrix[13] = -((matrixa[4] * matrixa[12]) + (matrixa[5] * matrixa[13]) + (matrixa[6] * matrixa[14]));
	//tempmatrix[13] = -matrixa[13];
	//tempmatrix[13] = -((matrixa[4] * matrixa[12]) + (matrixa[5] * matrixa[13]) + (matrixa[6] * matrixa[14]));
	tempmatrix[2] = matrixa[8];	tempmatrix[6] = matrixa[9];	tempmatrix[10] = matrixa[10];	tempmatrix[14] = -((matrixa[8] * matrixa[12]) + (matrixa[9] * matrixa[13]) + (matrixa[10] * matrixa[14]));
	//tempmatrix[14] = -matrixa[14];
	//tempmatrix[14] = -((matrixa[8] * matrixa[12]) + (matrixa[9] * matrixa[13]) + (matrixa[10] * matrixa[14]));
	tempmatrix[3] = 0.0f;		tempmatrix[7] = 0.0f;		tempmatrix[11] = 0.0f;		tempmatrix[15] = 1.0f;
	memcpy(matrixb,tempmatrix,16 * sizeof(GLfloat));
}

void identitymatrix(GLfloat *matrix) {
	matrix[0] = 1.0f;	matrix[4] = 0.0f;	matrix[8] = 0.0f;	matrix[12] = 0.0f;
	matrix[1] = 0.0f;	matrix[5] = 1.0f;	matrix[9] = 0.0f;	matrix[13] = 0.0f;
	matrix[2] = 0.0f;	matrix[6] = 0.0f;	matrix[10] = 1.0f;	matrix[14] = 0.0f;
	matrix[3] = 0.0f;	matrix[7] = 0.0f;	matrix[11] = 0.0f;	matrix[15] = 1.0f;
}

void scalematrix(GLfloat *matrix,GLfloat x,GLfloat y,GLfloat z,GLfloat w) {
	matrix[0] = x;		matrix[4] = 0.0f;	matrix[8] = 0.0f;	matrix[12] = 0.0f;
	matrix[1] = 0.0f;	matrix[5] = y;		matrix[9] = 0.0f;	matrix[13] = 0.0f;
	matrix[2] = 0.0f;	matrix[6] = 0.0f;	matrix[10] = z;		matrix[14] = 0.0f;
	matrix[3] = 0.0f;	matrix[7] = 0.0f;	matrix[11] = 0.0f;	matrix[15] = w;
}

void translatematrix(GLfloat *matrix,GLfloat x,GLfloat y,GLfloat z) {
	matrix[0] = 1.0f;	matrix[4] = 0.0f;	matrix[8] = 0.0f;	matrix[12] = x;
	matrix[1] = 0.0f;	matrix[5] = 1.0f;	matrix[9] = 0.0f;	matrix[13] = y;
	matrix[2] = 0.0f;	matrix[6] = 0.0f;	matrix[10] = 1.0f;	matrix[14] = z;
	matrix[3] = 0.0f;	matrix[7] = 0.0f;	matrix[11] = 0.0f;	matrix[15] = 1.0f;
}

void rotatematrix(GLfloat *matrix,double angle,GLfloat x,GLfloat y,GLfloat z) {
	GLfloat c = (GLfloat) cos(angle);
	GLfloat s = (GLfloat) sin(angle);
	GLfloat cm1 = 1 - c;
	GLfloat divby = sqrtf((x * x) + (y * y) + (z * z));
	x /= divby;
	y /= divby;
	z /= divby;
	matrix[0] = ((x * x) * cm1) + c;	matrix[4] = ((x * y) * cm1) - (z * s);	matrix[8] = ((x * z) * cm1) + (y * s);	matrix[12] = 0.0f;
	matrix[1] = ((x * y) * cm1) + (z * s);	matrix[5] = ((y * y) * cm1) + c;	matrix[9] = ((y * z) * cm1) - (x * s);	matrix[13] = 0.0f;
	matrix[2] = ((x * z) * cm1) - (y * s);	matrix[6] = ((y * z) * cm1) + (x * s);	matrix[10] = ((z * z) * cm1) + c;	matrix[14] = 0.0f;
	matrix[3] = 0.0f;			matrix[7] = 0.0f;			matrix[11] = 0.0f;			matrix[15] = 1.0f;
}

void orthprojmatrix(GLfloat *matrix,GLfloat left,GLfloat right,GLfloat bottom,GLfloat top,GLfloat near,GLfloat far) {
	matrix[0] = 2.0f / (right - left);	matrix[4] = 0.0f;			matrix[8] = 0.0f;			matrix[12] = (left + right) / (left - right);
	matrix[1] = 0.0f;			matrix[5] = 2.0f / (top - bottom);	matrix[9] = 0.0f;			matrix[13] = (bottom + top) / (bottom - top);
	matrix[2] = 0.0f;			matrix[6] = 0.0f;			matrix[10] = 2.0f / (near - far);	matrix[14] = (near + far) / (near - far);
	matrix[3] = 0.0f;			matrix[7] = 0.0f;			matrix[11] = 0.0f;			matrix[15] = 1.0f;
}