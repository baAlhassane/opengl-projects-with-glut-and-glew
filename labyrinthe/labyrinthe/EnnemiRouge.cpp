#include<glew.h>
#include<glut.h>
#include<iostream>

#include "EnnemiRouge.h"


EnnemiRouge::EnnemiRouge(Environnement& envJoueur): PersonageBase(envJoueur){
	
}
void EnnemiRouge::dessinerJoueur(int m) {

	glPushMatrix();
	glTranslated(posC+0.5,posL+0.5,0.0);
	// la tete 
	  glColor3d(0.9, 0.0, 0.0);
	  glPushMatrix();
	  glScaled(0.7, 1.0, 1.0);
	     glutSolidSphere(0.35, 12, 12);// Premiete ovale
	  glPopMatrix();
	  glPushMatrix();
	  glScaled(1.0, 0.7, 1.0);
	     glutSolidSphere(0.35, 12, 12);// deuxieme ovale
		 glPopMatrix();

		 // les yeux
		 
	  glColor3d(0.0, 0.0, 0.0);
	  glTranslated(0.13, -0.05, 0.0);
	     glutSolidSphere(0.07, 12, 12);// premiere  oeil
	  glTranslated(-0.26, 0.0, 0.0);
	    glutSolidSphere(0.07, 12, 12);   // deuxieme oeil
		glPopMatrix();

}

void EnnemiRouge::deplacerEnnemi() {



}


EnnemiRouge::~EnnemiRouge(){} 
