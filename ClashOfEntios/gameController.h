#pragma once
#include "Player.h"
#include "battlefield.h"
#include "Input.inl.hh"
#include <Windows.h>

class gameController
{
public:
	gameController(Player &p, battlefield &b, Player &p2);

	bool updateGame(Player::Entio *currentEntio, battlefield & b, Player *currentPlayer, Player *secondPlayer, int &lastX,int &lastY, int &turn, int &counter);
	
	Player &p;
	battlefield &b;
	Player &p2;
	

	//bool arrowThrowEntio(Player::Entio MyEntio);

	void lessFatigue(Player::Entio &MyEntio, Player &p);
	enti::InputKey waitUntilKeypressed();

	~gameController();
};


