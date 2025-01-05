#include <glew.h>
#include <glut.h>
#include <stdio.h>
#include "cube_rotatin_in_mvt.h"


int main(int argc, char* argv[]) {
   

    //Glut initialisation 
    glutInit(&argc, argv);

    cube_rotatin_in_mvt c;

    // init windows
    c.initWindows();

    // init GL
    c.initOpenGL();

    // display object
    glutDisplayFunc(cube_rotatin_in_mvt::display);

    //timer
    glutTimerFunc(0, cube_rotatin_in_mvt::timer, 0);
    

    // loop
    c.loop();
    return 0;
}





