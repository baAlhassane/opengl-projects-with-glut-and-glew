#include<glew.h>
#include<glut.h>
#include<iostream>
#include <stdio.h>

#include "wall/Wall.h"
#include "environnement/Environnement.h"

#include <functional>

// Wrapper global pour std::function
std::function<void()> displayFunction;
//std::function<void()> displayFunctionClavier;
// Fonction wrapper pour GLUT
void glutDisplayWrapper() {
	if (displayFunction) {
		displayFunction();
	}

}

Environnement* envPtr;
void glutSpecialWrapper(int key, int x, int y) {
	if (envPtr) {
		envPtr->specialKeyPressed(key, x, y);
	}
}






int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	std::cout << "hello world !" <<std::endl;;

	Wall wall;
	wall.loadFile("../lab.txt");

	std::cout << " wall.height eeeezzzzzz=  "<< wall.heigth<<std::endl;
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
		Environnement env(wall);
		envPtr = &env;
		
		env.iniWindows();

		//set opengl mode transformation
		env.initOpenGl();

		// Associer la méthode de l'objet à std::function
		displayFunction = [&env]() { env.display(); };
		glutDisplayFunc(glutDisplayWrapper);
		

		// Associer le wrapper à glutDisplayFunc
		

		// call display to dispaly the windows  
		//glutDisplayFunc(Environnement::display);

		// call the loop like glutMainLoop or  glutSwapBuffers(); // Échanger les tampons

		//envPtr = &env;
		glutSpecialFunc(glutSpecialWrapper);
		 // Associer un wrapper pour les touches spéciales avec lambda
		

		//glutReshapeFunc(Environnement::redimLab);
		Environnement::loop();




	}



	
	return 0;
}
