#include "gameController.h"




gameController::gameController(Player &p, battlefield &b):p(p), b(b)
{
}
Player::Entio lessFatigue(Player &p)
{
	int auxFatigue = 0 ;



}
void updateGame(Player::Entio &currentEntio, battlefield &b, Player &currentPlayer)
{
	enti::InputKey keyPressed;
	enti::systemPause();

	keyPressed = enti::getInputKey();

	if (keyPressed == enti::InputKey::W || keyPressed == enti::InputKey::w)
	{
		char aux;
		int posAuxX = currentEntio.posX;
		int posAuxY = currentEntio.posY + 1;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' || aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
		}
		else
		{
			char entio = currentEntio.name;
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.actualGround);
			currentEntio.posY++;
			currentEntio.actualGround = b.getCell(currentEntio.posX, currentEntio.posY);
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.name);
		}
	}
	else if (keyPressed == enti::InputKey::A || keyPressed == enti::InputKey::a)
	{
		char aux;
		int posAuxX = currentEntio.posX-1;
		int posAuxY = currentEntio.posY;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' || aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
		}
		else
		{
			char entio = currentEntio.name;
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.actualGround);
			currentEntio.posX--;
			currentEntio.actualGround = b.getCell(currentEntio.posX, currentEntio.posY);
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.name);
		}
	}
	else if (keyPressed == enti::InputKey::S || keyPressed == enti::InputKey::s)
	{
		char aux;
		int posAuxX = currentEntio.posX;
		int posAuxY = currentEntio.posY - 1;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' || aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
		}
		else
		{
			char entio = currentEntio.name;
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.actualGround);
			currentEntio.posY--;
			currentEntio.actualGround = b.getCell(currentEntio.posX, currentEntio.posY);
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.name);
		}
	}
	else if (keyPressed == enti::InputKey::D || keyPressed == enti::InputKey::d)
	{
		char aux;
		int posAuxX = currentEntio.posX + 1;
		int posAuxY = currentEntio.posY;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' || aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
		}
		else
		{
			char entio = currentEntio.name;
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.actualGround);
			currentEntio.posX++;
			currentEntio.actualGround = b.getCell(currentEntio.posX, currentEntio.posY);
			b.setCell(currentEntio.posX, currentEntio.posY, currentEntio.name);
		}
	}
	else if (keyPressed == enti::InputKey::ENTER)
	{
		
	}



}

gameController::~gameController()
{
}


