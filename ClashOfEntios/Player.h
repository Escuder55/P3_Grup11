#pragma once
#include "battlefield.h"


class Player
{
public:
	Player(int x, battlefield &b);

	struct Entio 
	{
		char name;
		int live;
		int posX;
		int posY;
		int arrows;
		int fatigue;
		char actualGround;
	};

	Entio MyEntio1, MyEntio2, MyEntio3, MyEntio4, MyEntio5, MyEntio6;

	int movements;

	int numberOfEntios;

	battlefield &b;

	~Player();


private:

	int getMovementsRemaining();

	bool arrowManagement(Entio MyEntio);

	int getFatiga(Entio MyEntio);
};

