#include "cube.h"
#include<glew.h>
#include<glut.h>

void cube::initWindows() {
	glutInitDisplayMode( GLUT_RGB | GL_DOUBLE);
	glutInitWindowSize(600, 500);
	glutCreateWindow("static cube  windows");

}

void cube::initOpenGL() {
	//glClearColor(0.0, 0.0, 0.0, 1.0f);//coleur de foind noire noire
   // glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 50.0); // Configuration de la perspective
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);// car y'a pas de camera 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cube::display() {
    //glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT);// appelle automatique glClearColor
   // glRotatef(45, 1.0f, 1.0f, 0.0f); // Rotation pour voir plusieurs faces
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10);
  
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



	
 //   glBegin(GL_QUADS);
 ////   //1- Face rouge front 1
 //   glColor3f(1.0, 0.0, 0.0);
 //   glVertex3f(1.0, 1.0, -1.0);
 //   glVertex3f(-1.0, 1.0, -1.0);
 //   glVertex3f(-1.0, 1.0, 1.0);
 //   glVertex3f(1.0, 1.0, 1.0);

 //   ////2- Face back (cyan)
 //   glColor3f(0.0, 1.0, 1.0);
 //   glVertex3f(1.0, -1.0, 1.0);
 //   glVertex3f(-1.0, -1.0, 1.0);
 //   glVertex3f(-1.0, -1.0, -1.0);
 //   glVertex3f(1.0, -1.0, -1.0);

 //   // 3- Face right (bleue)
 //  glColor3f(0.0, 0.0, 1.0);
 //   glVertex3f(1.0, 1.0, 1.0);
 //   glVertex3f(-1.0, 1.0, 1.0);
 //   glVertex3f(-1.0, -1.0, 1.0);
 //   glVertex3f(1.0, -1.0, 1.0);


 //   glColor3f(0.0, 0.0, 1.0);
 //   glVertex3f(1.0, 1.0, 1.0);
 //   glVertex3f(1.0, -1.0, 1.0);
 //   glVertex3f(-1.0, -1.0, 1.0);
 //   glVertex3f(-1.0, 1.0, 1.0);


 //   //4-  Face left (jaune)
 //   glColor3f(1.0, 1.0, 0.0);
 //   glVertex3f(1.0, -1.0, -1.0);
 //   glVertex3f(-1.0, -1.0, -1.0);
 //   glVertex3f(-1.0, 1.0, -1.0);
 //   glVertex3f(1.0, 1.0, -1.0);

 //   ////5- Face top (violette)
 //   glColor3f(1.0, 0.0, 1.0);
 //   glVertex3f(-1.0, 1.0, 1.0);
 //   glVertex3f(-1.0, 1.0, -1.0);
 //   glVertex3f(-1.0, -1.0, -1.0);
 //   glVertex3f(-1.0, -1.0, 1.0);

 //   //6-  Face bottom (verte)
 //   glColor3f(0.0, 1.0, 0.0);
 //   glVertex3f(1.0, 1.0, -1.0);
 //   glVertex3f(1.0, 1.0, 1.0);
 //   glVertex3f(1.0, -1.0, 1.0);
 //   glVertex3f(1.0, -1.0, -1.0);

    //glEnd();
    //glutSwapBuffers();

   
}

void cube::loop() {
    glutMainLoop();
}

// Test of this code 
//int main(int argc, char* argv[]) {
//
//
//    //Glut initialisation 
//    glutInit(&argc, argv);
//
//    cube c;
//
//    // init windows
//    c.initWindows();
//
//    // init GL
//    c.initOpenGL();
//
//    // display object
//    glutDisplayFunc(cube::display);
//
//
//    // loop
//    c.loop();
//    return 0;
//}


