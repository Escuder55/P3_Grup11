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

	Player::Entio lessFatigue(Player &p, Player::Entio &MyEntio);

	//bool arrowThrowEntio(Player::Entio MyEntio);

	~gameController();
};

