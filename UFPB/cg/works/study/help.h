GLfloat* nvf1(GLfloat x) {
	return (GLfloat[]) { x };
}

GLfloat* nvf3(GLfloat x, GLfloat y, GLfloat z) {
	return (GLfloat[]) { x, y, z };
}

GLfloat* nvf4(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	return (GLfloat[]) { x, y, z, w };
}

GLfloat* vf3tovf4(const GLfloat vf3[], GLfloat w) {
	return nvf4(vf3[0], vf3[1], vf3[2], w);
}