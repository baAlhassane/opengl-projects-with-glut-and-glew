
#include<glew.h>
#include<glut.h>

#include<iostream> 
#include<vector>

//#include "Environnement.h"

//#include "../wall/Wall.h"
//#include "../joueur/Joueur.h";
#include "Environnement.h"



void Environnement::iniWindows() {
  
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE) ;

	glutCreateWindow(" labyrinthe ");
}


void Environnement::initOpenGl() {
	

	glClearColor(1.0, 1.0, 1.0, 1.0); // Couleur de fond (blanc)
	glViewport(0, 0, 500, 500); // Adapter à la taille de la fenêtre

	// Projection orthographique
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); // Les coordonnées correspondent à i, j
	//glOrtho(0, WIDTH, 0, HEIGHT, -1, 1); // Les coordonnées correspondent à i, j
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Environnement::loop() {

	glutMainLoop();

}

void Environnement::freeMemorybeforeExit() {

}



void Environnement::displayLab() {

	glColor3d(0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	std::cout << " \nin Environnement::displayLab() debut \n " ; 
	for (int i = 0; i <HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << matrice[i][j];

			if (matrice[i][j] == '0') {

				glVertex2d(j, i);          // Coin haut-gauche
				glVertex2d(j, i + 1);      // Coin bas-gauche
				glVertex2d(j + 1, i + 1);  // Coin bas-droit
				glVertex2d(j + 1, i);      // Coin haut-droit
				
			
			}	
		}
		
		std::cout << std::endl;
	}
	glEnd();
	

	
	glPushMatrix();
	glTranslated(ExitC + 3.5, ExitL + 0.5, 0.0);
	glColor3d(0.3, 1.0, 0.3); //green color
	//draw many quads with different side or size.
	for (double size = 0.1; size < 1.0; size += 0.2) {
		glutWireCube(size);
	}
	glPopMatrix();
	

	//glFlush();
	
	
	//joueur1.dessinerJoueur();
	std::cout << " \nin Environnement::displayLab() fin \n ";

}

Environnement::Environnement(const Wall& wall): wallEnv(wall), HEIGHT(wall.getHeight()), WIDTH(wall.getWidth()),
 matrice(wall.getDatav()),joueur1(*this) {

	
	//matrice.resize(HEIGHT);
	std::cout << " ----- \n wall.data[i][j] in Environnement(const Wall& wall) \n";
	std::cout << "  WIDTH= "<<WIDTH<< std::endl;
	std::cout << "  HEIGHT "<<HEIGHT <<std::endl;;
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout <<"  wallEnv.getDatav()[i][j] : " << wallEnv.getDatav()[i][j];
			//matrice[i].push_back(wallEnv.getDatav()[i][j]);
			//std::cout << matrice[i][j];

			switch (matrice[i][j]) {
				
			  case 'j':
			  case 'J': {
			
				break;
			}
			}
	
		}

	

		
		//std::cout <<" ---------- " << i <<std::endl;


	}
	std::cout << "Instance Environnement initialisée, adresse : " << this << std::endl;


	
}



void Environnement::display() {

	displayLab();
	joueur1.dessinerJoueur();
	//glFlush();
	glutSwapBuffers();
	

}
void Environnement::testVictoire() {
	//std::cout << " joueur1.getPosC() =  " << joueur1.getPosC() << " joueur1.getPosL() =  " << joueur1.getPosL() << std::endl;
	
	if (joueur1.getPosC() == 3 && joueur1.getPosL() == 0) {
		display();
		std::cout << " joueur1.getPosC() =  " << joueur1.getPosC() << " joueur1.getPosL() =  " << joueur1.getPosL() << std::endl;
		std::cout << "Game over ! You win !!!" << std::endl;
		system("pause");
		exit(1);
		 
	}

}

void Environnement::specialKeyPressed(int key, int x, int y) {
	switch (key) {

	case GLUT_KEY_UP :   joueur1.moveToUp(); break;
	case GLUT_KEY_DOWN:  joueur1.moveToDown(); break;
	case GLUT_KEY_LEFT:  joueur1.moveToLeft(); break;
	case GLUT_KEY_RIGHT: joueur1.moveToRight(); break;
	}
	testVictoire();
	glutPostRedisplay();
}

Environnement* Environnement::currentInstance = nullptr;

void Environnement::specialKeyWrapper(int key, int x, int y) {
	if (currentInstance) {
		currentInstance->specialKeyPressed(key, x, y);
	}
}


Environnement::~Environnement() {
}


void Environnement::redimLab(int x, int y){
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)WIDTH, (double)HEIGHT, 0.0);
}

