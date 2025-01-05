#include <glew.h>
#include <glut.h>
#include <stdio.h>
#include "triangle.h"
#include "cube_with_glut_depth.h"


int main(int argc, char* argv[]) {
   

    //Glut initialisation 
    glutInit(&argc, argv);

    cube_with_glut_depth c;

    // init windows
    c.initWindows();

    // init GL
    c.initOpenGL();

    // display object
    glutDisplayFunc(cube_with_glut_depth::display);
    

    // loop
    c.loop();
    return 0;
}





