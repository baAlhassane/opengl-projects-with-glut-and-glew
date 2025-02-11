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
	PersonageBase* suivant;
	
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
	virtual ~PersonageBase()=default;
	virtual void dessinerJoueur(int num)=0;
	virtual void deplacerEnnemi() = 0; // M�thode purement virtuelle (obligatoire � red�finir)
	PersonageBase* getSuivant() const;
	void setSuivant(PersonageBase* p);
	void removeJoueur(PersonageBase* joueur);

	

	
};

