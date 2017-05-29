#include "gameController.h"



gameController::gameController(Player &p, battlefield &b):p(p), b(b)
{
}


gameController::~gameController()
{
}


Player::Entio lessFatigue (Player &p, Player :: Entio MyEntio)
{
	int auxFatigue = MyEntio.fatigue;
	Player::Entio auxEntio = MyEntio; 
	
	if (p.MyEntio1.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio1;
		auxFatigue = auxEntio.fatigue;
	}

	if (p.MyEntio2.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio2;
		auxFatigue = auxEntio.fatigue;
	}

	if (p.MyEntio3.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio3;
		auxFatigue = auxEntio.fatigue;
	}

	if (p.MyEntio4.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio4;
		auxFatigue = auxEntio.fatigue;
	}

	if (p.MyEntio5.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio5;
		auxFatigue = auxEntio.fatigue;
	}

	if (p.MyEntio6.fatigue < auxFatigue)
	{
		auxEntio = p.MyEntio6;
		auxFatigue = auxEntio.fatigue;
	}

	return auxEntio;

}