#pragma once
#include "Wall.h"
#include <vector>
class Environnement
{
public:
	void iniWindows();
	void initOpenGl();
	static void redimLab(int x, int y);
	static void displayLab();
	static void display();
	static void loop();
	Wall wallEnv;
	static std::vector<std::vector<char>> matrice;
	static  int HEIGHT;
     static int WIDTH;

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








