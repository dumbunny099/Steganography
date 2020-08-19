#include <iostream>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "simulator.h"
using namespace std;

int length = 100;
simulator Simulator(500, length/2, 2.0, 3.0);

void Initialize(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("FLing: Unified GPU Physics");

	glMatrixMode(GL_PROJECTION);
	glOrtho(-10, length + 10, -10, length + 10, -10, length + 10);
	glMatrixMode(GL_MODELVIEW);
}

void draw_boundary() {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(length, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, length, 0);
	glVertex3f(length, 0, 0);
	glVertex3f(length, length, 0);
	glVertex3f(0, length, 0);
	glVertex3f(length, length, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, length);
	glVertex3f(0, length, 0);
	glVertex3f(0, length, length);
	glVertex3f(length, 0, 0);
	glVertex3f(length, 0, length);
	glVertex3f(length, length, 0);
	glVertex3f(length, length, length);
	glVertex3f(0, 0, length);
	glVertex3f(length, 0, length);
	glVertex3f(0, 0, length);
	glVertex3f(0, length, length);
	glVertex3f(length, 0, length);
	glVertex3f(length, length, length);
	glVertex3f(0, length, length);
	glVertex3f(length, length, length);
	glEnd();
}

void Render() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, length / 2 + 10, 0, 0, 0, 0, 1, 0);
	draw_boundary();
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex3f(length/2, length / 2, length / 2);
	Simulator.draw();
	glEnd();
	glutSwapBuffers();
}

void update(int value) {
	Simulator.simulation();
	glutTimerFunc(25, update, 0);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	Initialize(argc,argv);
	glutDisplayFunc(Render);
	glutTimerFunc(2000, update, 0);
	glutMainLoop();
	return 0;
}