#pragma once
//#include "../environnement/Environnement.h"
class Environnement;  // Déclaration anticipée
class Joueur
{
private:
	int posC;
	int posL;
	//Add to know the width and height oft the labyrinth.
	//for the constrains of its moving
	Environnement& env;
	int HEIGHT;
	int WIDTH;
	 std::vector<std::vector<char>> matriceJoueur;


public:
	void moveToUp();
	void moveToDown();
	void moveToLeft();
	void moveToRight();
	//void labyKeybord(int key, int x, int y);


	void dessinerJoueur();
	int getPosC() const;
	int getPosL() const;
	void setPosC(int x);
	void setPosL(int y);
	//void setEnv(Environnement en); // No need this 
	Joueur(Environnement& envJoueur);
	~Joueur();


};

