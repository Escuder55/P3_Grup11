#pragma once
#include "Player.h"
#include "battlefield.h"
#include "Input.inl.hh"
#include <Windows.h>

class gameController
{
public:
	gameController(Player &p, battlefield &b);

	Player &p;
	battlefield &b;
	bool updateGame(Player::Entio &currentEntio, battlefield &b, Player &currentPlayer);
	Player::Entio lessFatigue(Player &p, Player::Entio &MyEntio);

	//bool arrowThrowEntio(Player::Entio MyEntio);

	~gameController();
};

