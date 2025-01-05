#include "cube_rotation_after_set_depth_test.h"
#include<glew.h>
#include<glut.h>

void cube_rotation_after_set_depth_test::initWindows() {
    glutInitDisplayMode(GLUT_RGB | GL_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600, 500);
    glutCreateWindow("static cube  windows");

}

void cube_rotation_after_set_depth_test::initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0f);//coleur de foind noire noire
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluPerspective(60.0, 1.0, 1, 50.0); // Configuration de la perspective
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);// car y'a pas de camera 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cube_rotation_after_set_depth_test::display() {
    //glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// appelle automatique glClearColor
    // glRotatef(45, 1.0f, 1.0f, 0.0f); // Rotation pour voir plusieurs faces
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0);
    glRotatef(60.0, 1.0, 1.0, 1.0);

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

void cube_rotation_after_set_depth_test::loop() {
    glutMainLoop();
}


