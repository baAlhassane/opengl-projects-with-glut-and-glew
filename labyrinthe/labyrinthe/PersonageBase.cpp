#include "PersonageBase.h"

#include<glew.h>
#include<glut.h>
#include<iostream>
#include<vector>


#include"./environnement/Environnement.h"  // Seulement ici, pas dans `Joueur.h`

//PersonageBase::PersonageBase(){
//
//	posC = 0;
//	posL = 0;
//	//env = 0;
//}


void PersonageBase::moveToDown() {
	if (posL < HEIGHT - 1 && matriceJoueur[posL + 1][posC] != '0')
		//++posL; // we statrt a the top at left where posC and posL = 0,0
		posL++;
	std::cout << " deplacement en bas de  " << posC << " , " << posL << std::endl;
}
void PersonageBase::moveToUp() {
	if (posL > 0 && matriceJoueur[posL - 1][posC] != '0')
		//--posL; // because when we up we try to rich the origine
		posL--;
	std::cout << " deplacement en haut de  " << posC << " , " << posL << std::endl;
}

void PersonageBase::moveToLeft() {
	if (posC > 0 && matriceJoueur[posL][posC - 1] != '0')
		//--posC;; // because when we up we try to rich the origine
		posC--;
	std::cout << " deplacement a gauche de  " << posC << " , " << posL << std::endl;
}


void PersonageBase::moveToRight() {
	if (posC < WIDTH - 1 && matriceJoueur[posL][posC + 1] != '0')
		//++posC;; // because when we up we try to rich the origine
		posC++;
	std::cout << " deplacement a droite de  " << posC << " , " << posL << std::endl;
}

PersonageBase::PersonageBase(Environnement& envJoueur) : env(envJoueur) {

     	posC = 0;
	    posL = 0;

	HEIGHT = env.getHEIGHT();
	WIDTH = env.getWIDTH();
	std::cout << " ( HEIGHT, WIDTH  ) dansJoueur::Joueur(Environnement& envJoueur) : " << std::endl;
	std::cout << " ( HEIGHT, WIDTH  ) : " << HEIGHT << " , " << WIDTH << " pas " << std::endl;
	//matriceJoueur.resize(HEIGHT);
	matriceJoueur = envJoueur.getMatrice();

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << " blbba  " << matriceJoueur[i][j];
			//matriceJoueur[i].push_back(env.getMatrice()[i][j]);
			//std::cout << envJoueur.getMatrice().size();
		}
		std::cout << std::endl;
	}

}

int PersonageBase::getPosC() const {
	return posC;
}

int PersonageBase::getPosL() const {
	return posL;
}

void PersonageBase::setPosC(int x) {
	posC = x;
}
void PersonageBase::setPosL(int y) {
	posL = y;
}

void PersonageBase::dessinerJoueur(int numero) {

}


