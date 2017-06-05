#include "Player.h"
#include "battlefield.h"



Player::Player(int x, battlefield &b):b(b)
{
	if (x == 1)
	{
		MyEntio1 = { 'A', 10, 18, 16, 10, 0, '.' };
		MyEntio2 = { 'B', 10, 16, 17, 10, 0, '.' };
		MyEntio3 = { 'C', 10, 20, 17, 10, 0, '.' };
		MyEntio4 = { 'D', 10, 16, 18, 10, 0, '.' };
		MyEntio5 = { 'E', 10, 20, 18, 10, 0, '.' };
		MyEntio6 = { 'F', 10, 18, 19, 10, 0, '.' };

		numPlayer = 1;


	}
	else if (x == 2)
	{
		MyEntio1 = { '1', 10, 54, 16, 10, 0, '.' };
		MyEntio2 = { '2', 10, 52, 17, 10, 0, '.' };
		MyEntio3 = { '3', 10, 56, 17, 10, 0, '.' };
		MyEntio4 = { '4', 10, 52, 18, 10, 0, '.' };
		MyEntio5 = { '5', 10, 56, 18, 10, 0, '.' };
		MyEntio6 = { '6', 10, 21, 54, 19, 0, '.' };

		numPlayer = 2;

	}

	

}


int Player::getMovementsRemaining()
{
	return movements;
}

bool Player::arrowManagement(Entio MyEntio)
{
	if (MyEntio.arrows > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Player::getFatiga(Entio MyEntio)
{
	return MyEntio.fatigue;
}

void Player::decreaseEntios()
{
	numberOfEntios--;
}

void Player::movementsDecrease()
{
	if(movements > 0) movements--;
	
}


Player::~Player()
{
}
