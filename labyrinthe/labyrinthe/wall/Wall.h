#pragma once
#include<vector> 
class Wall
{
public: 
	void loadFile(const char* file);
	int heigth;
	int width;
	 int HEIGHT;
	int WIDTH;
	char** data;//matrice 2D

	int getHeight() const;
	int getWidth()  const;
	char** getData();
	std::vector<std::vector<char >> matrice;
	std::vector<std::vector<char >> getDatav() const;

	//Wall(const Wall& wall);


	~Wall();
};



