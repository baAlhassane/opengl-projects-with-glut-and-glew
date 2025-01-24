#include<glew.h>
#include<glut.h>
#include<iostream>
#include"Wall.h"

#include "Environnement.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	std::cout << "hello world !" <<std::endl;;

	Wall wall;
	wall.loadFile("../lab.txt");

	std::cout << " wall.height =  "<< wall.heigth<<std::endl;
	std::cout<< " wall.width =  " << wall.width << std::endl  ;
	int width = wall.width ;
	int height = wall.heigth;
	for (int i = 0; i < width; i++) {
		//std::cout << wall.data[i + 3] << std::endl;
		
		for (int j = 0; j < height; j++) {
			std::cout<<wall.data[i][j];
			
		}
		std::cout << std::endl;



		//Glut initialisation 
		

		//Windows Set for triangle instance
		Environnement t(wall);
		t.iniWindows();

		//set opengl mode transformation
		t.initOpenGl();

		// call display to dispaly the windows  
		glutDisplayFunc(Environnement::display);

		// call the loop like glutMainLoop or  glutSwapBuffers(); // Échanger les tampons

		//glutReshapeFunc(Environnement::redimLab);
		Environnement::loop();




	}



	
	return 0;
}