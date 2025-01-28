#pragma once
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

	//Wall(const Wall& wall);


	~Wall();
};



