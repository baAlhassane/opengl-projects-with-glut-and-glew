#pragma once

#include <vector>
#include "../wall/Wall.h"
#include "Environnement.h"
#include "../joueur/Joueur.h"
//class Joueur;
#include "../PersonageBase.h"

enum ENUMTYPE;
class PersonageBase;
class Environnement{
private:
	 Wall wallEnv;
	 int HEIGHT;
	 int WIDTH;
	 int ExitC; // exit point de sortie
	 int ExitL;
	 std::vector<std::vector<char>> matrice;
	 std::unique_ptr<PersonageBase> joueur1;
	 std::vector<std::unique_ptr<PersonageBase>> joueurs;
	 static int TIMER_MILLIS;
		
		 

	 
public:
	void iniWindows();
	void initOpenGl();
	void redimLab(int x, int y);
    void displayLab();
	void display();
	void specialKeyPressed(int key, int x, int y);
	static void specialKeyWrapper(int key, int x, int y);
	static Environnement* currentInstance;
	static void loop();
	void addJoueur(std::unique_ptr<PersonageBase> joueur, int posL, int posC);
	int indexJoueurActif = 0; // Par défaut, on sélectionne le premier personnage
	void changerJoueurActif(); // Nouvelle méthode pour changer de joueur
	void testVictoire();
	static void glutDisplayFuncWrapper();
	 void timer(int v);
	static void glutTimerWrapper(int v);

	

	void freeMemorybeforeExit();
	int getHEIGHT() const {
		return HEIGHT;
	}
	int getWIDTH() const {
		return WIDTH;
	}
	  std::vector<std::vector<char>> getMatrice() const  {

		return matrice;
	}

	Environnement(const Wall& wall);
	~Environnement();


	};

enum ENUMTYPE {
	JOUEUR,
	ENNEMIROUGE,
	ENNEMIVERT
};







