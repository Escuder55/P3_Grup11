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
		int posY;
		int posX;
		int arrows;
		int fatigue;
		char actualGround;
	};

	int numPlayer;

	Entio MyEntio1, MyEntio2, MyEntio3, MyEntio4, MyEntio5, MyEntio6;

	battlefield &b;
	int numberOfEntios = 6;

	int getMovementsRemaining();

	bool arrowManagement(Entio MyEntio);

	int getFatiga(Entio MyEntio);



	void decreaseEntios();
	void movementsDecrease();

	~Player();

//private:

	int movements = 10;

	

};

