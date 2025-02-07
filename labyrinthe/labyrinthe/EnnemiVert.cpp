#include "EnnemiVert.h"
#include <random>

//void dessinerJoueur(int numero);
//EnnemiVert(Environnement& envJoueur);
//void deplacer();
//~EnnemiVert();
#include<glew.h>
#include<glut.h>

#include<iostream> 
#include<vector>
EnnemiVert::EnnemiVert(Environnement& envEnemiVert):PersonageBase(envEnemiVert) {



}

void EnnemiVert::dessinerJoueur(int numero) {
	glPushMatrix();
	  glTranslated(posC+0.5, posL+0.5,0.0);
	   //la tete
	  glColor3d(0.0, 0.9, 0.0);// couleur verte
	  glutSolidSphere(0.3, 12, 12);//sphere de la tete

	  // Les cornes
	  glPushMatrix();
	    glTranslated(0.0, -0.13,0.0);
	    glScaled(1.0, 0.5, 1.0);
		glutSolidCube(0.5);
		glPopMatrix();


	   // Les yeux
		glColor3d(1.0, 0.0, 0.0);
		glTranslated(-0.3, -0.1, 0.0);// Se placer a la position du premier oeil.
		//dessin des trois yeux
		for (int i = 0; i < 3; i++) {
			glTranslated(0.15, 0.0, 0.0);
			glutSolidSphere(0.05, 12, 12);
		}


		glPopMatrix();


}

EnnemiVert::~EnnemiVert() {}


void EnnemiVert::deplacerEnnemi(){

		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<int> distrib(0, 3);

		int hasard = distrib(gen);

		switch (hasard) {
		case 0: moveToUp(); break;
		case 1: moveToDown(); break;
		case 2: moveToLeft(); break;
		case 3: moveToRight(); break;
		}
	


}