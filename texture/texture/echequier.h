#pragma once

#include<glew.h>
#include<glut.h>
class echequier
{

public:
	static const int width= 64;
    static const int height = 64 ;
	void makeCheckImage();
	void init();
	static void display();
	void reshape(int n, int m);
	void keybord(unsigned char key, int x, int y);
	GLubyte checkImage[width][height][3];


};

