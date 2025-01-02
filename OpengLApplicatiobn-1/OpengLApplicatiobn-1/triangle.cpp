#include "triangle.h"
#include<stdio.h>
#include<glew.h>
#include<glut.h>



void triangle::initOpengl() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);// Here is not necessary because we havent camero o objet to place and display
	glLoadIdentity();
	
}



void triangle::initGlut(int argc, char** argv) {
	glutInit(&argc, argv);
}


void triangle::initWindows() {

	glutInitWindowSize(500, 500);

	//glutInitDisplayMode(GL_);
	glutInitWindowSize(250, 250);// no necessary here 
    glutInitWindowPosition(100, 100);// no necessary here 
	glutCreateWindow("OpenGL avec GLUT");
}

void triangle::display() {

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();

}

void triangle::loop() {



	glutMainLoop();

}

