#pragma once

#include <vector>
#include "../wall/Wall.h"
#include "../joueur/Joueur.h"

class Environnement
{
public:
	void iniWindows();
	void initOpenGl();
	void redimLab(int x, int y);
    void displayLab();
	void display();
	static void loop();
	Wall wallEnv;

	static std::vector<std::vector<char>> matrice;
	static  int HEIGHT;
    static int WIDTH;

	 Joueur joueur1;

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








