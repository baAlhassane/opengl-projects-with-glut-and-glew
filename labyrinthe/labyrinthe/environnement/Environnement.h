#pragma once

#include <vector>
#include "../wall/Wall.h"
#include "Environnement.h"
#include "../joueur/Joueur.h"

class Joueur;

class Environnement
{
private:
	
	/*int HEIGHT;
	  int WIDTH;
	 Joueur joueur1*/;
	 Wall wallEnv;
	 int HEIGHT;
	 int WIDTH;
	 
	 
	 static std::vector<std::vector<char>> matrice;
	 Joueur joueur1;  // Déclaré après HEIGHT et WIDTH


public:
	void iniWindows();
	void initOpenGl();
	void redimLab(int x, int y);
    void displayLab();
	void display();
	//void labyKeybord(int key, int x, int y);
	void specialKeyPressed(int key, int x, int y);
	void specialKeyWrapper(int key, int x, int y);
	static Environnement* currentInstance;
	static void loop();
	//Wall wallEnv;
	



	//static std::vector<std::vector<char>> matrice;
	///*int HEIGHT;
 //     int WIDTH;
	// Joueur joueur1*/;

	// int HEIGHT;
	// int WIDTH;
	// Wall wallEnv;
	// Joueur joueur1;  // Déclaré après HEIGHT et WIDTH

	int getHEIGHT() const {
		return HEIGHT;
	}
	int getWIDTH() const {
		return WIDTH;
	}
	std::vector<std::vector<char>> getMatrice() {
		return matrice;
	}

	Environnement(const Wall& wall);
	~Environnement();


	};








