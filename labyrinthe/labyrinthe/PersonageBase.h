#pragma once
#include<vector>

class Environnement;
class PersonageBase
{
protected:
	int posC;
	int posL;
	int HEIGHT;
	int WIDTH;
	Environnement& env;
	std::vector<std::vector<char>> matriceJoueur;
public:
	 void moveToUp();
     void moveToDown();
     void moveToLeft();
     void moveToRight();
	 int  getPosC() const;
	 int  getPosL() const;
	 void setPosC(int x);
	 void setPosL(int y);
	PersonageBase(Environnement& envJoueur);
	virtual ~PersonageBase()=0;
	virtual void dessinerJoueur(int num)=0;
	virtual void deplacerEnnemi() = 0; // Méthode purement virtuelle (obligatoire à redéfinir)
};

