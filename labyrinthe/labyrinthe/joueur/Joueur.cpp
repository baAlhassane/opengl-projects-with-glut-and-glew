
#include<glew.h>
#include<glut.h>
#include<iostream>
#include<vector>
#include<string>


#include "Joueur.h"
#include"../environnement/Environnement.h"  // Seulement ici, pas dans `Joueur.h`



void Joueur::dessinerJoueur(int numero) {
    glPushMatrix();
	  
    	glTranslated( posC+0.5, posL+0.5, 0.0);
	    //glTranslated( 3, 0, 0.0);
	    glColor3d(0.0, 0.0, 0.0);
	    glutSolidSphere(0.3, 12, 12);// the head is a sphere
	
     	glColor3d(1.0, 1.0, 0.0);
	    glTranslated(0.0, -0.1, 0.0);
	      glutSolidSphere(0.05, 12, 12);// first eye

	    glTranslated(-0.2, 0.0, 0.0);
	      glutSolidSphere(0.05, 12, 12);// second eye

		  glPopMatrix();



		  // Affichage du numéro au-dessus du joueur
		  glPushMatrix();
		  glColor3d(1.0, 1.0, 1.0); // Couleur blanche pour le texte
		  glRasterPos3f(posC + 0.3, posL + 0.65, 0.0); // Position du texte

		  std::string numStr = std::to_string(numero); // Convertir le numéro en string
		  for (char c : numStr) {
			  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		  }

		  glPopMatrix();
		   

}



Joueur::Joueur( Environnement& envJ ) : PersonageBase(envJ) {

}

void Joueur::deplacerEnnemi(){
	

}
//
//
//void Joueur::moveToDown() {
//	if (posL < HEIGHT - 1 && matriceJoueur[posL + 1][posC] != '0')
//		//++posL; // we statrt a the top at left where posC and posL = 0,0
//		posL++;
//	std::cout << " deplacement en bas de  " << posC << " , " << posL << std::endl;
//}
//void Joueur::moveToUp() {
//	if (posL > 0 && matriceJoueur[posL - 1][posC] != '0')
//		//--posL; // because when we up we try to rich the origine
//		posL--;
//	std::cout << " deplacement en haut de  " << posC << " , " << posL << std::endl;
//}
//
//void Joueur::moveToLeft() {
//	if (posC > 0 && matriceJoueur[posL][posC - 1] != '0')
//		//--posC;; // because when we up we try to rich the origine
//		posC--;
//	std::cout << " deplacement a gauche de  " << posC << " , " << posL << std::endl;
//}
//
//
//void Joueur::moveToRight() {
//	if (posC < WIDTH - 1 && matriceJoueur[posL][posC + 1] != '0')
//		//++posC;; // because when we up we try to rich the origine
//		posC++;
//	std::cout << " deplacement a droite de  " << posC << " , " << posL << std::endl;
//}
//
//int Joueur::getPosC() const {
//	return posC;
//}
//
//int Joueur::getPosL() const {
//	return posL;
//}
//
//void Joueur::setPosC(int x) {
//	posC = x;
//}
//void Joueur::setPosL(int y) {
//	posL = y;
//}
//
//
//
//
Joueur::~Joueur(){}
//
//
//
//
//
