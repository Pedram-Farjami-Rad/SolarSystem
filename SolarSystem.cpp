#include <GL/glut.h>

GLfloat angle, angle1, angle2;
GLfloat speedMultiplier = 1.0f; // Speed multiplier for rotation
bool isRotating = true; // Flag to control rotation

void setupLighting() {
    GLfloat light_position[] = {5.0, 5.0, 5.0, 1.0}; // Light position
    GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};    // Light color
    GLfloat ambient_light[] = {0.2, 0.2, 0.2, 1.0};  // Ambient light

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void drawGround() {
    glColor3f(0.3, 0.3, 0.3); // Dark gray ground
    glBegin(GL_QUADS);
        glVertex3f(-10.0, -10.0, 0.0);
        glVertex3f(10.0, -10.0, 0.0);
        glVertex3f(10.0, 10.0, 0.0);
        glVertex3f(-10.0, 10.0, 0.0);
    glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 0, 20, // camera position (x, y, z)
		0, 0, 0, // look at point
		0, 1, 0); // up vector

	drawGround();

	// Dodecahedron (gold)
	glColor3f(1.0, 0.84, 0.0);
	glPushMatrix();
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 3.0, 0.5);
	glRotatef(angle2, 0.0, 0.0, 1.0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidDodecahedron();
	glPopMatrix();

	// Teapot (red)
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glTranslatef(7.0, 0.0, 0.5);
	glRotatef(angle1, 0.0, 0.0, 1.0);
	glutSolidTeapot(0.7);
	glPopMatrix();

	// Sphere (blue)
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(angle2, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.5);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	// Torus (green)
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	glutSolidTorus(0.3, 0.7, 20, 20);
	glPopMatrix();

	glutSwapBuffers();
}

void init() {
	glClearColor(0.1, 0.1, 0.1, 1.0); // Dark gray background
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 0.5, 1.0, 100); // Perspective projection
	glMatrixMode(GL_MODELVIEW);
	setupLighting();
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

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glutIdleFunc(test);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}