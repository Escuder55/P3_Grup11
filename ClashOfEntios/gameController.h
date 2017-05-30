#pragma once
#include "Player.h"
#include "battlefield.h"
#include "Input.inl.hh"
#include <Windows.h>

class gameController
{
public:
	gameController(Player &p, battlefield &b, Player &p2);

	bool updateGame(Player::Entio & currentEntio, battlefield & b, Player & currentPlayer, Player & secondPlayer);

	Player &p;
	battlefield &b;
	Player &p2;
	

	//bool arrowThrowEntio(Player::Entio MyEntio);

	Player::Entio lessFatigue(Player & p, Player::Entio & MyEntio);

	enti::InputKey waitUntilKeypressed();

	~gameController();
};


