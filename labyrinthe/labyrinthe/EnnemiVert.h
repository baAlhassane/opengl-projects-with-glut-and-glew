#pragma once
#include "PersonageBase.h"
class EnnemiVert: public PersonageBase
{
public:
	void dessinerJoueur(int numero);
	EnnemiVert(Environnement& envJoueur);
	void deplacerEnnemi();
	virtual ~EnnemiVert();
	


};


