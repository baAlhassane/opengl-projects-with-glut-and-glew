#pragma once

#include"../PersonageBase.h"


class Joueur : public PersonageBase
{
public: 
	//void labyKeybord(int key, int x, int y);
	
	void dessinerJoueur(int numero);
	Joueur(Environnement& envJoueur);
	void deplacerEnnemi();
	~Joueur();


};

