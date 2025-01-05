#include <glew.h>
#include <glut.h>
#include <stdio.h>
#include "triangle.h"
#include "cube.h"


int main(int argc, char* argv[]) {
   

    //Glut initialisation 
    glutInit(&argc, argv);

    cube c;

    // init windows
    c.initWindows();

    // init GL
    c.initOpenGL();

    // display object
    glutDisplayFunc(cube::display);
    

    // loop
    c.loop();
    return 0;
}





