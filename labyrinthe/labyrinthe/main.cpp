#include<glew.h>
#include<glut.h>
#include<iostream>
#include <stdio.h>
#include "joueur/Joueur.h"
#include "wall/Wall.h"
#include "environnement/Environnement.h"
#include "joueur/joueur.h"
#include "EnnemiVert.h"
#include "EnnemiRouge.h"
#include <functional>
#include<memory>

// Wrapper global pour std::function
std::function<void()> displayFunction;

// Fonction wrapper pour GLUT
void glutDisplayWrapper() {
	if (displayFunction) {
		displayFunction();
	}

}

Environnement* envPtr;
void glutSpecialWrapper(int key, int x, int y) {
	if (envPtr) {		envPtr->specialKeyPressed(key, x, y);
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
		//Joueur joueur1
		
	  
		env.addJoueur(std::make_unique<Joueur>(env), 1, 0);  // Premier joueur
		env.addJoueur(std::make_unique<Joueur>(env), 3, 5);  // Deuxième joueur, position différente
		env.addJoueur(std::make_unique<Joueur>(env),5 , 4);
		//env.addJoueure(std::make_unique<EnemiBase>(env));
		env.addJoueur(std::make_unique<Joueur>(env), 1,6 );  // Premier joueur
		env.addJoueur(std::make_unique<EnnemiVert>(env),6 , 1);
		env.addJoueur(std::move(std::make_unique<EnnemiRouge>(env)), 2, 3);
		
		std::unique_ptr<Joueur> joueur = std::make_unique<Joueur>(env);
		auto ptr = joueur.get();// utile pour le remove; Car apres move on le pert
		env.addJoueur(std::move(joueur), 4, 4);
		env.removeJoueur(ptr);
		
		


		env.iniWindows();

		//set opengl mode transformation
		env.initOpenGl();

		// Associer la méthode de l'objet à std::function
		//displayFunction = [&env]() { env.display(); };
		//glutDisplayFunc(glutDisplayWrapper);

		 glutDisplayFunc(Environnement::glutDisplayFuncWrapper);
			
		//envPtr = &env;
		//glutSpecialFunc(glutSpecialWrapper);
		  env.currentInstance = &env;
		 glutSpecialFunc(Environnement::specialKeyWrapper);// Associer un wrapper pour les touches spéciales avec lambda
		
		//glutReshapeFunc(Environnement::redimLab);

		 const int TIMER_MILLIS = 100;
		 glutTimerFunc(TIMER_MILLIS, Environnement::glutTimerWrapper, 0);

		// glutTimerFunc(TIMER_MILLIS,Environnement::glutTimercWrapper,0);
		Environnement::loop();


	}



	
	return 0;
}
