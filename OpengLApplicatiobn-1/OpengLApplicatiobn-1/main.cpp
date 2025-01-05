#include <glew.h>
#include <glut.h>
#include <stdio.h>
#include "triangle.h"
#include "cube_rotation_after_set_depth_test.h"


int main(int argc, char* argv[]) {
   

    //Glut initialisation 
    glutInit(&argc, argv);

    cube_rotation_after_set_depth_test c;

    // init windows
    c.initWindows();

    // init GL
    c.initOpenGL();

    // display object
    glutDisplayFunc(cube_rotation_after_set_depth_test::display);
    

    // loop
    c.loop();
    return 0;
}





