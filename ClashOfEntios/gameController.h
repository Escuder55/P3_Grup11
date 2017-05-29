#pragma once
#include "Player.h"
#include "battlefield.h"
#include "Input.inl.hh"

class gameController
{
public:
	gameController(Player &p, battlefield &b);

	Player &p;
	battlefield &b;

	Player::Entio lessFatigue(Player MyPlayer);
	void updateGame();
	//bool arrowThrowEntio(Player::Entio MyEntio);

	~gameController();
};

