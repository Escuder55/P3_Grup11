#include "gameController.h"




gameController::gameController(Player &p, battlefield &b):p(p), b(b)
{
}

bool gameController::updateGame(Player::Entio &currentEntio, battlefield & b, Player & currentPlayer, Player &secondPlayer)
{

	bool exit = false;

	enti::InputKey keyPressed;
	//enti::systemPause();

	//system("pause");

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
			system("pause");
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
		int posAuxX = currentEntio.posX - 1;
		int posAuxY = currentEntio.posY;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' || aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
			system("pause");
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
			system("pause");
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
			system("pause");
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

	else if (keyPressed == enti::InputKey::ESC)
	{

		enti::cout << enti::Color::WHITE << "Are you sure you want to exit? (Y/N)" << enti::endl;
		enti::cout << enti::cend;

		char finish;

		std::cin >> finish;

		if (finish == 'Y' || finish == 'y')
		{
			exit = true;
		}

		else if (finish == 'N' || finish == 'n')
		{

		}
		else
		{
			std::cout << "That is not a valid input";
		}

	}

	else if (keyPressed == enti::InputKey::SPACEBAR)
	{
		std::cout << "Press 1 to attack with sword" << std::endl;
		std::cout << "Press 2 to attack with sword" << std::endl;

		int weapon;
		std::cin >> weapon;

		switch (weapon)
		{

			int direction;

		case 1:
			std::cout << "Press 1 to attack up" << std::endl;
			std::cout << "Press 2 to attack left" << std::endl;
			std::cout << "Press 3 to attack down" << std::endl;
			std::cout << "Press 4 to attack right" << std::endl;

			std::cin >> direction;

			if (currentPlayer.numPlayer == 1)
			{
				switch (direction)
				{
					char attackCell;
				case 1:
					attackCell = b.getCell(currentEntio.posX, currentEntio.posY + 1);

					if (secondPlayer.MyEntio1.name == attackCell)
					{
						secondPlayer.MyEntio1.live = 0;
						secondPlayer.decreaseEntios();
					}

					else if (secondPlayer.MyEntio2.name == attackCell)
					{
						secondPlayer.MyEntio2.live = 0;
						secondPlayer.decreaseEntios();
					}

					else if (secondPlayer.MyEntio3.name == attackCell)
					{
						secondPlayer.MyEntio3.live = 0;
						secondPlayer.decreaseEntios();
					}

					else if (secondPlayer.MyEntio4.name == attackCell)
					{
						secondPlayer.MyEntio4.live = 0;
						secondPlayer.decreaseEntios();
					}

					else if (secondPlayer.MyEntio5.name == attackCell)
					{
						secondPlayer.MyEntio5.live = 0;
						secondPlayer.decreaseEntios();
					}

					else if (secondPlayer.MyEntio6.name == attackCell)
					{
						secondPlayer.MyEntio6.live = 0;
						secondPlayer.decreaseEntios();
					}

					else
					{
						std::cout << "Attack Missed" << std::endl;
					}


				default:
					break;
				}
			}



			break;

		case 2:
			std::cout << "Press 1 to attack up" << std::endl;
			std::cout << "Press 2 to attack left" << std::endl;
			std::cout << "Press 3 to attack down" << std::endl;
			std::cout << "Press 4 to attack right" << std::endl;

			std::cin >> direction;

			break;
		}
	}

	//enti::systemPause();

	return exit;

}

Player::Entio gameController::lessFatigue(Player & p, Player::Entio & MyEntio)
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




gameController::~gameController()
{
}

