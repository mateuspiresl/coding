/* gcc -o file file.c -lglut -lGL -lGLU */
/* gcc -g code.c -lopengl32 -lglu32 -lfreeglut */

#include <GL/glut.h>
#include <stdio.h>

void display();
void keyEventHandler(unsigned char key, int x, int y);

// struct QuadFaceNode;
// QuadFaceNode* readCube(char* filename);
// void drawCube(QuadFaceNode* node);

int moveHor = 0;
int moveVer = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);

	int windowID = glutCreateWindow("OPENGL");

    glutKeyboardFunc(keyEventHandler);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':   moveVer = 1;
                    break;
        case 's':   moveVer = -1;
                    break;
        case 'a':   moveHor = -1;
                    break;
        case 'd':   moveHor = 1;
                    break;
	}
    
    printf("%d %d\n", moveHor, moveVer);

    glutPostRedisplay();
} 

void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -50);
    
    glScaled(10, 10, 0);

	glPopMatrix();
	glRotated(moveHor * 10, 0, 1, 0);
    glRotated(moveVer * 10, 1, 0, 0);
	glPushMatrix();
	
    drawCube(readCube("cubo.obj"));

    // Reset movement
    moveHor = 0;
    moveVer = 0;

	glutSwapBuffers();
}