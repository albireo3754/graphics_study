#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/GLU.h>

#define _WINDOW_WIDTH 300
#define _WINDOW_HEIGHT 300

int mode = 0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	if (mode == 0) {
		glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glEnd();
	}
	else {
		glutWireTeapot(0.7);
	}
	
	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y)
{
	switch (KeyPressed) {
	case 'a':
		mode = (mode + 1) % 2;
		break;
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	}
	glutPostRedisplay();
}

void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)_WINDOW_WIDTH;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)_WINDOW_HEIGHT;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.2, 1.0, 1.0, 1.0);

	//�ݹ� ���
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutReshapeFunc(MyReshape);

	glutMainLoop();
	return 0;
}