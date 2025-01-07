#pragma once
class echequier
{
#define  width 64;
#define height 64;

	void makeCheckImage();
	void init();
	static void display();
	void reshape(int n, int m);
	void keybord(unsigned char key, int x, int y);


};

