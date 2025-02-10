#pragma once
#include"PersonageBase.h"
class EnnemiRouge: public PersonageBase
{

public:
	EnnemiRouge(Environnement& envJoueur);
	void dessinerJoueur(int m);
	void deplacerEnnemi();
	~EnnemiRouge();

	

};


