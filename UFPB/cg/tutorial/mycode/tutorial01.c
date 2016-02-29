/*
	http://ogldev.atspace.co.uk/www/tutorial01/tutorial01.html
*/

#include <GL/glut.h>

void render();

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

	// Sets the display callback for the current window
	glutDisplayFunc(render);

	// Enters the GLUT event processing loop
	glutMainLoop();

	return 0;
}

void render()
{
	// Clear buffers to preset values
	// GL_COLOR_BUFFER_BIT: Indicates the buffers currently enabled for color writing
	glClear(GL_COLOR_BUFFER_BIT); 
	// Swaps the buffers of the current window if double buffered
	glutSwapBuffers();
}