#include <glew.h>
#include <glut.h>
#include <stdio.h>
#include "triangle.h"



int main(int argc, char* argv[]) {
   

    //Glut initialisation 
    glutInit(&argc, argv);

    //Windows Set for triangle instance
    triangle t;
    t.initWindows();
    
    //set opengl mode transformation
    t.initOpengl();

    // call display to dispaly the windows  
    glutDisplayFunc(triangle::display);

    // call the loop like glutMainLoop or  glutSwapBuffers(); // Échanger les tampons

    triangle::loop();
 
    return 0;
}

