#include <GL/glut.h>

GLfloat angle, angle1, angle2;
GLfloat speedMultiplier = 1.0f; // Speed multiplier for rotation
bool isRotating = true; // Flag to control rotation

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
	if (isRotating) {
		angle += 1.0 * speedMultiplier;
		angle1 += 2.0 * speedMultiplier;
		angle2 += 0.5 * speedMultiplier;
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '+':// increase speed
		speedMultiplier += 0.1f;
		break;
	case '-':// decrease speed
		speedMultiplier -= 0.1f;
		if (speedMultiplier < 0.1f) speedMultiplier = 0.1f; // Prevent negative speed
		break;
	case 's':case 'S': // toggle rotation
		isRotating = !isRotating;
		break;
	case '0':// Reset speed to default
		speedMultiplier = 1.0f;
		break;
	}
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glutIdleFunc(test);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
}