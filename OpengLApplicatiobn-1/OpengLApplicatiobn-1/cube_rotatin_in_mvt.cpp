#include "cube_rotatin_in_mvt.h"
#include<glew.h>
#include<glut.h>



float cube_rotatin_in_mvt::angle = 0;


void cube_rotatin_in_mvt::initWindows() {
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600, 500);
    glutCreateWindow("static cube  windows");

}

void cube_rotatin_in_mvt::initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0f);//coleur de foind noire noire
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluPerspective(60.0, 1.0, 1, 50.0); // Configuration de la perspective
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);// car y'a pas de camera 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cube_rotatin_in_mvt::display() {
    //glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// appelle automatique glClearColor
    // glRotatef(45, 1.0f, 1.0f, 0.0f); // Rotation pour voir plusieurs faces
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0);
    glRotatef(angle, 1.0, 1.0, 1.0);

    // dans display glclear; glLoadIdentity;gltTranslate;
    // dans reshape glMatrixMode(Projection);glLoadIdentity;glutPerspective; glMatrixMode(LodevelView)

    glBegin(GL_QUADS);
    //1- front Red 
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    //2 - back Green
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    //3- right Blue
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //4- left Yellow 
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    //5- top Cyan 
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //6 bottom magenta //violette
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glutSwapBuffers();
}

void cube_rotatin_in_mvt::loop() {
    glutMainLoop();
}

void cube_rotatin_in_mvt::timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    angle += 0.8;
    if (angle > 360.0) {
        angle = angle - 360.0;
    }
}



