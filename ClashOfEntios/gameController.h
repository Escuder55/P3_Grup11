#pragma once
#include "Player.h"
#include "battlefield.h"

class gameController
{
public:
	gameController(Player &p, battlefield &b);

	Player &p;
	battlefield &b;

	Player::Entio lessFatigue(Player MyPlayer);

	//bool arrowThrowEntio(Player::Entio MyEntio);

	~gameController();
};

