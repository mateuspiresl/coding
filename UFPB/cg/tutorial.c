/*
	http://ogldev.atspace.co.uk/www/tutorial01/tutorial01.html
*/

#include <GL/glut.h>

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(800, 480);
	glutInitWindowPosition(50, 25);

	// GLUT_SINGLE: single buffered window
	// DOUBLE_SINGLE: double buffered window
	// GLUT_RGBA: RGBA mode window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	// Creates a top-level window
	int windowID = glutCreateWindow("Tutorial");

	// Enters the GLUT event processing loop
	glutMainLoop();


	return 0;
}