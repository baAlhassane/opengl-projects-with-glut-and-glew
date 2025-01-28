#include "Joueur.h"
#include<glew.h>
#include<glut.h>

Joueur::Joueur() {
	posC = 0;
	posL = 0;

}


int Joueur::getPosC() const{
	return posC;
}

int Joueur::getPosL() const {
	return posL;
}

void Joueur::setPosC(int x) {
	posC = x;
}
 void Joueur::setPosL(int y) {
	 posL=y;
}

void Joueur::dessinerJoueur() {
    glPushMatrix();

    	glTranslated( posC, posL, 0.0);
	    //glTranslated( 3, 0, 0.0);
	    glColor3d(0.0, 0.0, 0.0);
	    glutSolidSphere(0.3, 12, 12);// the head is a sphere
	
     	glColor3d(1.0, 1.0, 0.0);
	    glTranslated(0.0, -0.1, 0.0);
	      glutSolidSphere(0.05, 12, 12);// first eye

	    glTranslated(-0.2, 0.0, 0.0);
	      glutSolidSphere(0.05, 12, 12);// second eye

		  glPopMatrix();


}

Joueur::~Joueur(){}