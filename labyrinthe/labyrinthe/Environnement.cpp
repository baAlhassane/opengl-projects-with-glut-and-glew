#include "Environnement.h"
#include<glew.h>
#include<glut.h>
#include"Wall.h"
#include<iostream> 
#include<vector>

void Environnement::iniWindows() {
  
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE) ;

	glutCreateWindow(" labyrinthe ");
}


void Environnement::initOpenGl() {
	/*
	* Lecture avec des coordées réels dans [-1 , 1]
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1, 1, -1, 1, -1,1);
	glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); // Les coordonnées correspondent à i, j
	glMatrixMode(GL_MODELVIEW);// Here is not necessary because we havent camero o objet to place and display
	glLoadIdentity();
	*/
	

	glClearColor(1.0, 1.0, 1.0, 1.0); // Couleur de fond (blanc)
	glViewport(0, 0, 500, 500); // Adapter à la taille de la fenêtre

	// Projection orthographique
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); // Les coordonnées correspondent à i, j
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Environnement::loop() {



	glutMainLoop();

}




std::vector < std::vector<char>> Environnement::matrice;;
int Environnement::HEIGHT = 0;
int Environnement::WIDTH = 0;


/*
void Environnement::displayLab() {
	glClear(GL_COLOR_BUFFER_BIT);  // Effacer l'écran avec la couleur de fond
	glColor3d(0.5, 0.5, 0.5);     // Couleur des murs

	std::cout << " \nin Environnement::displayLab() debut \n ";

	glBegin(GL_QUADS); // Démarrer la définition des quadrilatères

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << matrice[i][j];

			if (matrice[i][j] == '0') {
				// Convertir les coordonnées pour l'espace [-1, 1]
				double x1 = -1.0 + (2.0 * j) / WIDTH;    // Coordonnée x de gauche
				double x2 = -1.0 + (2.0 * (j + 1)) / WIDTH; // Coordonnée x de droite
				double y1 = 1.0 - (2.0 * i) / HEIGHT;   // Coordonnée y du haut
				double y2 = 1.0 - (2.0 * (i + 1)) / HEIGHT; // Coordonnée y du bas

				// Dessiner le quadrilatère
				glVertex2d(x1, y1);
				glVertex2d(x1, y2);
				glVertex2d(x2, y2);
				glVertex2d(x2, y1);
			}
		}
		std::cout << std::endl;
	}

	glEnd(); // Fin de la définition des quadrilatères

	std::cout << " \nin Environnement::displayLab() fin \n ";
	glFlush(); // S'assurer que le dessin est exécuté immédiatement
}

*/


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
				
				//glVertex2d(i, j);
				//glVertex2d(i, j + 1);
				//glVertex2d(i + 1, j + 1);
				//glVertex2d(i + 1, j);	
			}	
		}
		std::cout << std::endl;
	}
	glEnd();
	glFlush();

	std::cout << " \nin Environnement::displayLab() fin \n ";

}


Environnement::Environnement(const Wall& wall) {
	wallEnv =wall;
	WIDTH = wall.getWidth();
	HEIGHT = wall.getHeight();
	matrice.resize(HEIGHT);
	std::cout << " ----- \n wall.data[i][j] in Environnement(const Wall& wall) \n";
	std::cout << "  WIDTH= "<<WIDTH<< std::endl;
	std::cout << "  HEIGHT "<<HEIGHT <<std::endl;;
	//std::vector<char> v;
	for (int i = 0; i < HEIGHT; i++) {

		for (int j = 0; j < WIDTH; j++) {
			//std::cout << wall.data[i][j] ;
			matrice[i].push_back(wall.data[i][j]);
	
		}
		
		//std::cout <<" ---------- " << i <<std::endl;


	}

	std::cout << "___________________________ \n";
}

void Environnement::display() {

	displayLab();
	glFlush();
	

}

Environnement::~Environnement() {
}


void Environnement::redimLab(int x, int y){
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)WIDTH, (double)HEIGHT, 0.0);
}