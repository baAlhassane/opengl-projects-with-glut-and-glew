
#include<glew.h>
#include<glut.h>
#include<iostream> 
#include<vector>
#include "Environnement.h"
#include "../EnnemiVert.h"



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
	std::cout << " \nin Environnement::displayLab() fin \n ";
}

void Environnement::addJoueur(std::unique_ptr<PersonageBase> joueur, int posL, int posC) {
	joueur->setPosL(posL);
	joueur->setPosC(posC);

	joueurs.push_back(std::move(joueur));

}


//int indexJoueurActif = 0; // Par défaut, on sélectionne le premier personnage

void Environnement::changerJoueurActif() {
	if (!joueurs.empty()) {
		indexJoueurActif = (indexJoueurActif + 1) % joueurs.size(); // Passer au joueur suivant
		std::cout << "Joueur actif changé : " << indexJoueurActif << std::endl;
	}
}

Environnement::Environnement(const Wall& wall): wallEnv(wall), HEIGHT(wall.getHeight()), WIDTH(wall.getWidth()),
 matrice(wall.getDatav()) {
	
	std::cout << " ----- \n wall.data[i][j] in Environnement(const Wall& wall) \n";
	std::cout << "  WIDTH= "<<WIDTH<< std::endl;
	std::cout << "  HEIGHT "<<HEIGHT <<std::endl;;
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout <<"  wallEnv.getDatav()[i][j] : " << wallEnv.getDatav()[i][j];
			switch (matrice[i][j]) {
			  case 'j':
			  case 'J': {
				break;
			}
			}
	
		}

	}
	std::cout << "Instance Environnement initialisée, adresse : " << this << std::endl;
}


void Environnement::display() {

	displayLab();

	int i = 0;
	for (auto& joueur : joueurs) {
		++i;
		joueur->dessinerJoueur(i); // Appelle la méthode polymorphique
	}
	

	//joueur1->dessinerJoueur();
	//glFlush();
	
	glutSwapBuffers();
	//currentInstance->timer(500000);
	

}
void Environnement::testVictoire() {


	for (auto& joueur : joueurs) {
		//joueur->dessinerJoueur(); // Appelle la méthode polymorphique}

		if (joueur->getPosC() == 3 && joueur->getPosL() == 0) {
			display();
			std::cout << " joueur1.getPosC() =  " << joueur->getPosC() << " joueur.getPosL() =  " << joueur->getPosL() << std::endl;
			std::cout << "Game over ! You win !!!" << std::endl;
			system("pause");
			exit(1);
		}
	}
}


void Environnement::specialKeyPressed(int key, int x, int y) {
	if (joueurs.empty()) return;
	std::cout << "Touche appuyée: " << key << std::endl;
	std::cout << "Touche appuyée : (x,y) = " << x <<" , "  << y << std::endl;
	// Obtenir le joueur actif
	auto& personnageActif = joueurs[indexJoueurActif];
	if (auto ptrJoueur = dynamic_cast<Joueur*>(personnageActif.get())) {
		std::cout << "C'est un Joueur !" << std::endl;
		switch (key) {
		case GLUT_KEY_UP:  personnageActif->moveToUp(); break;
		case GLUT_KEY_DOWN:  personnageActif->moveToDown(); break;
		case GLUT_KEY_LEFT:  personnageActif->moveToLeft(); break;
		case GLUT_KEY_RIGHT:   personnageActif->moveToRight(); break;
		case GLUT_KEY_F1:  changerJoueurActif(); break;  // Changer de joueur avec F1
		}
		
		testVictoire();
		glutPostRedisplay();
		
	}


	


	}
		

	
		



Environnement* Environnement::currentInstance = nullptr;

void Environnement::specialKeyWrapper(int key, int x, int y) {
	if (currentInstance) {
		currentInstance->specialKeyPressed(key, x, y);
	}
}
 

 void Environnement::glutDisplayFuncWrapper() {
	 if (currentInstance) {
		 currentInstance->display();
	 }

}


 void Environnement::glutTimerWrapper(int v) {
	 if (currentInstance) {
		 currentInstance->timer(v);
	 }



 }



 int Environnement::TIMER_MILLIS = 500;

 void Environnement::timer(int v) {
	 if (joueurs.empty()) return;

	 // Boucle sur tous les joueurs pour déplacer uniquement les ennemis
	 for (auto& joueur : joueurs) {
		 if (auto ennemi = dynamic_cast<EnnemiVert*>(joueur.get())) {
			 ennemi->deplacerEnnemi();
		 }
	 }

	 testVictoire();
	 glutPostRedisplay();
	 const int v1 = v;
	 // Relance le timer pour un prochain appel
	 glutTimerFunc(TIMER_MILLIS, glutTimerWrapper, 0);
 }


Environnement::~Environnement() {
}


void Environnement::redimLab(int x, int y){
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)WIDTH, (double)HEIGHT, 0.0);
}

