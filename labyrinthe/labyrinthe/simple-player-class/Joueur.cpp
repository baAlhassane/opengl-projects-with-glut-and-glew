
#include<glew.h>
#include<glut.h>
#include<iostream>
#include<vector>

//#include"../environnement/Environnement.h"
//#include "Joueur.h"


#include "Joueur.h"
#include"../environnement/Environnement.h"  // Seulement ici, pas dans `Joueur.h`


void Joueur::moveToDown() {
	if (posL < HEIGHT - 1 && matriceJoueur[posL + 1][posC] != '0')
		//++posL; // we statrt a the top at left where posC and posL = 0,0
		posL++;
	std::cout << " deplacement en bas de  " << posC << " , " <<posL<<std::endl;
}
void Joueur::moveToUp() {
	if (posL > 0 && matriceJoueur[posL - 1][posC] != '0')
		//--posL; // because when we up we try to rich the origine
		posL--;
	std::cout << " deplacement en haut de  "  << posC << " , " << posL << std::endl;
}

void Joueur::moveToLeft() {
	if (posC > 0 && matriceJoueur[posL][posC - 1] != '0')
		//--posC;; // because when we up we try to rich the origine
		posC--;
	std::cout << " deplacement a gauche de  " << posC << " , " << posL << std::endl;
}


void Joueur::moveToRight() {
	if (posC < WIDTH-1 && matriceJoueur[posL][posC+1] != '0' )
		//++posC;; // because when we up we try to rich the origine
		posC++;
	std::cout << " deplacement a droite de  " << posC << " , " << posL << std::endl;
}

//std::vector<std::vector<char>> Joueur::matriceJoueur;

// constructor with no parameters works well.
// But the probleme is we don't know the HEIGHT and WIDTH for the Joueur.
//  We add env in the construction to know or reach information from the conatiner
Joueur::Joueur(Environnement& envJoueur): env(envJoueur){
	posC = 0;
	posL = 0;

	

	HEIGHT = env.getHEIGHT();
	WIDTH = env.getWIDTH();
	std::cout << " ( HEIGHT, WIDTH  ) dansJoueur::Joueur(Environnement& envJoueur) : " << std::endl;
	std::cout << " ( HEIGHT, WIDTH  ) : " <<  HEIGHT << " , " << WIDTH << " pas " << std::endl;
	//matriceJoueur.resize(HEIGHT);
	matriceJoueur = envJoueur.getMatrice();

	for (int i = 0; i < HEIGHT;i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << " blbba  "<< matriceJoueur[i][j]; 
			//matriceJoueur[i].push_back(env.getMatrice()[i][j]);
			//std::cout << envJoueur.getMatrice().size();
		}
		std::cout << std::endl;
}




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


}



Joueur::~Joueur(){}



/* // Here we have the code with on constrain about the side of the labyrinth.


#include<glew.h>
#include<glut.h>
#include<iostream>

//#include"../environnement/Environnement.h"
//#include "Joueur.h"


#include "Joueur.h"
#include"../environnement/Environnement.h"  // Seulement ici, pas dans `Joueur.h`


void Joueur::moveToDown() {
	if(posL < HEIGHT-1)
	posL++; // we statrt a the top at left where posC and posL = 0,0
	std::cout << " deplacement en bas de  " << posL << " pas " << std::endl;
}
void Joueur::moveToUp() {
	if(posL>0)
	posL--; // because when we up we try to rich the origine
	std::cout << " deplacement en haut de  " << posL << " pas " << std::endl;
}

void Joueur::moveToLeft() {
	if (posC > 0)
	posC--;; // because when we up we try to rich the origine
	std::cout << " deplacement a gauche de  " << posC << " pas " << std::endl;
}


void Joueur::moveToRight() {
	if (posC < WIDTH-1 )
	posC++;; // because when we up we try to rich the origine
	std::cout << " deplacement a droite de  " << posC << " pas " << std::endl;
}



// constructor with no parameters works well.
// But the probleme is we don't know the HEIGHT and WIDTH for the Joueur.
//  We add env in the construction to know or reach information from the conatiner
Joueur::Joueur(Environnement& envJoueur): env(envJoueur){
	posC = 0;
	posL = 0;

	HEIGHT = env.getHEIGHT();
	WIDTH = env.getWIDTH();
	std::cout << " ( HEIGHT, WIDTH  ) dansJoueur::Joueur(Environnement& envJoueur) : " << std::endl;
	std::cout << " ( HEIGHT, WIDTH  ) : " <<  HEIGHT << " , " << WIDTH << " pas " << std::endl;

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


}



Joueur::~Joueur(){}



*/