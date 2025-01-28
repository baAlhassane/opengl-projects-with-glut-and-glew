#pragma once
class Joueur
{
private:
	int posC;
	int posL;

public:
	void dessinerJoueur();
	int getPosC() const;
	int getPosL() const;
	void setPosC(int x);
	void setPosL(int y);
	Joueur();
	~Joueur();


};

