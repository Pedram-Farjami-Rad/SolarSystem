#include <GL/glut.h>

GLfloat angle, angle1, angle2;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 3.0, 0.0);
	glRotatef(angle2, 0.0, 0.0, 1.0);
	glScalef(0.3, 0.3, 0.3);
	glutWireDodecahedron();
	glLoadIdentity;
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glTranslatef(7.0, 0.0, 0.0);

	glRotatef(angle1, 0.0, 0.0, 1.0);
	glutWireTeapot(0.7);
	glRotatef(angle2, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);

	glutWireSphere(0.5, 6, 6);

	glLoadIdentity();
	glRotatef(angle, 0.0, 0.0, 1.0);
	glutWireTorus(0.3, 0.7, 10, 10);
	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void test() {
	angle += 1.0;
	angle1 += 2.0;
	angle2 += 0.5;
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glutIdleFunc(test);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}