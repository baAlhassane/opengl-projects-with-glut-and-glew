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
	 int ExitC; // exit point
	 int  ExitL;
	 
	 
	 std::vector<std::vector<char>> matrice;
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

	void freeMemorybeforeExit();
	void testVictoire();
	
	



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
	  std::vector<std::vector<char>> getMatrice() const  {
		  //if (joueur1.getPosC() > 0) { std::cout << "Erreur : "<< joueur1.getPosC() ;  }
		//if (matrice.empty()) {
		//	std::cerr << "Erreur : matrice non initialisée !" << std::endl;
		//	// Tu pourrais aussi renvoyer une matrice vide ou gérer l'erreur d'une autre manière
		//}


		//std::cout << "Appel de getMatrice(), taille : " << matrice.size() << std::endl;
		//std::cout << "getMatrice() appelé sur instance : " << this << ", taille : " << matrice.size() << std::endl;


		return matrice;
	}

	Environnement(const Wall& wall);
	~Environnement();


	};








