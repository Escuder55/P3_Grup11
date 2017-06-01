#include "gameController.h"







gameController::gameController(Player & p, battlefield & b, Player & p2): p(p), b(b), p2(p2)
{
}

bool gameController::updateGame(Player::Entio *currentEntio, battlefield & b, Player *currentPlayer, Player *secondPlayer)
{
	bool exit = false;

	enti::InputKey keyPressed;
	//enti::systemPause();

	//system("pause");

	keyPressed = gameController::waitUntilKeypressed();

	if (keyPressed == enti::InputKey::W || keyPressed == enti::InputKey::w)
	{
		char aux;
		int posAuxX = currentEntio->posX - 1;
		int posAuxY = currentEntio->posY;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' && aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
			system("pause");
		}
		else
		{
			char entio = currentEntio->name;
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->actualGround);
			currentEntio->posX--;
			currentEntio->actualGround = b.getCell(currentEntio->posX, currentEntio->posY);
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->name);
		}
	}
	else if (keyPressed == enti::InputKey::A || keyPressed == enti::InputKey::a)
	{
		char aux;
		int posAuxX = currentEntio->posX;
		int posAuxY = currentEntio->posY - 1;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' && aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
			system("pause");
		}
		else
		{
			char entio = currentEntio->name;
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->actualGround);
			currentEntio->posY--;
			currentEntio->actualGround = b.getCell(currentEntio->posX, currentEntio->posY);
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->name);
		}
	}
	else if (keyPressed == enti::InputKey::S || keyPressed == enti::InputKey::s)
	{
		char aux;
		int posAuxX = currentEntio->posX + 1;
		int posAuxY = currentEntio->posY;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' && aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
			system("pause");
		}
		else
		{
			char entio = currentEntio->name;
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->actualGround);
			currentEntio->posX++;
			currentEntio->actualGround = b.getCell(currentEntio->posX, currentEntio->posY);
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->name);
		}
	}
	else if (keyPressed == enti::InputKey::D || keyPressed == enti::InputKey::d)
	{
		char aux;
		int posAuxX = currentEntio->posX;
		int posAuxY = currentEntio->posY + 1;

		aux = b.getCell(posAuxX, posAuxY);
		if (aux != '.' && aux != ':')
		{
			std::cout << "You cannot do this movement" << std::endl;
			system("pause");
		}
		else
		{
			char entio = currentEntio->name;
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->actualGround);
			currentEntio->posY++;
			currentEntio->actualGround = b.getCell(currentEntio->posX, currentEntio->posY);
			b.setCell(currentEntio->posX, currentEntio->posY, currentEntio->name);
		}
	}
	else if (keyPressed == enti::InputKey::ENTER)
	{
		char answer;
		std::cout << "1.Change the current Entio\n" <<
			"2.Change the current Player" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
		case '1':		
			*currentEntio = currentPlayer->MyEntio2;
			break;
		case '2':
			currentPlayer = secondPlayer;
			*currentEntio = currentPlayer->MyEntio1;

			break;
		}
		
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
		std::cout << "Press 1 to attack with Sword" << std::endl;
		std::cout << "Press 2 to attack with Bow" << std::endl;

		int weapon;
		std::cin >> weapon;

		switch (weapon)
		{

			int direction;

			char attackCell;

		case 1:
			std::cout << "Press 1 to attack up" << std::endl;
			std::cout << "Press 2 to attack left" << std::endl;
			std::cout << "Press 3 to attack down" << std::endl;
			std::cout << "Press 4 to attack right" << std::endl;

			std::cin >> direction;


			switch (direction)
			{

			case 1:
				attackCell = b.getCell(currentEntio->posX - 1, currentEntio->posY);

				if (secondPlayer->MyEntio1.name == attackCell)
				{
					secondPlayer->MyEntio1.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio1.posX, secondPlayer->MyEntio1.posY, secondPlayer->MyEntio1.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio2.name == attackCell)
				{
					secondPlayer->MyEntio2.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio2.posX, secondPlayer->MyEntio2.posY, secondPlayer->MyEntio2.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio3.name == attackCell)
				{
					secondPlayer->MyEntio3.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio3.posX, secondPlayer->MyEntio3.posY, secondPlayer->MyEntio3.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio4.name == attackCell)
				{
					secondPlayer->MyEntio4.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio4.posY, secondPlayer->MyEntio4.posX, secondPlayer->MyEntio4.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio5.name == attackCell)
				{
					secondPlayer->MyEntio5.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio5.posX, secondPlayer->MyEntio5.posY, secondPlayer->MyEntio5.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio6.name == attackCell)
				{
					secondPlayer->MyEntio6.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio6.posX, secondPlayer->MyEntio6.posY, secondPlayer->MyEntio6.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else
				{
					std::cout << "Attack Missed" << std::endl;
					enti::systemPause();
				}

				break;

			case 2:
				attackCell = b.getCell(currentEntio->posX, currentEntio->posY - 1);

				if (secondPlayer->MyEntio1.name == attackCell)
				{
					secondPlayer->MyEntio1.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio1.posX, secondPlayer->MyEntio1.posY, secondPlayer->MyEntio1.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio2.name == attackCell)
				{
					secondPlayer->MyEntio2.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio2.posX, secondPlayer->MyEntio2.posY, secondPlayer->MyEntio2.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio3.name == attackCell)
				{
					secondPlayer->MyEntio3.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio3.posX, secondPlayer->MyEntio3.posY, secondPlayer->MyEntio3.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio4.name == attackCell)
				{
					secondPlayer->MyEntio4.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio4.posX, secondPlayer->MyEntio4.posY, secondPlayer->MyEntio4.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio5.name == attackCell)
				{
					secondPlayer->MyEntio5.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio5.posX, secondPlayer->MyEntio5.posY, secondPlayer->MyEntio5.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio6.name == attackCell)
				{
					secondPlayer->MyEntio6.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio6.posX, secondPlayer->MyEntio6.posY, secondPlayer->MyEntio6.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else
				{
					std::cout << "Attack Missed" << std::endl;
					enti::systemPause();
				}

				break;

			case 3:
				attackCell = b.getCell(currentEntio->posX + 1, currentEntio->posY);

				if (secondPlayer->MyEntio1.name == attackCell)
				{
					secondPlayer->MyEntio1.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio1.posX, secondPlayer->MyEntio1.posY, secondPlayer->MyEntio1.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio2.name == attackCell)
				{
					secondPlayer->MyEntio2.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio2.posX, secondPlayer->MyEntio2.posY, secondPlayer->MyEntio2.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio3.name == attackCell)
				{
					secondPlayer->MyEntio3.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio3.posX, secondPlayer->MyEntio3.posY, secondPlayer->MyEntio3.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio4.name == attackCell)
				{
					secondPlayer->MyEntio4.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio4.posX, secondPlayer->MyEntio4.posY, secondPlayer->MyEntio4.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio5.name == attackCell)
				{
					secondPlayer->MyEntio5.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio5.posX, secondPlayer->MyEntio5.posY, secondPlayer->MyEntio5.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio6.name == attackCell)
				{
					secondPlayer->MyEntio6.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio6.posX, secondPlayer->MyEntio6.posY, secondPlayer->MyEntio6.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else
				{
					std::cout << "Attack Missed" << std::endl;
					enti::systemPause();
				}

				break;

			case 4:
				attackCell = b.getCell(currentEntio->posX, currentEntio->posY + 1);

				if (secondPlayer->MyEntio1.name == attackCell)
				{
					secondPlayer->MyEntio1.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio1.posX, secondPlayer->MyEntio1.posY, secondPlayer->MyEntio1.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio2.name == attackCell)
				{
					secondPlayer->MyEntio2.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio2.posX, secondPlayer->MyEntio2.posY, secondPlayer->MyEntio2.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio3.name == attackCell)
				{
					secondPlayer->MyEntio3.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio3.posX, secondPlayer->MyEntio3.posY, secondPlayer->MyEntio3.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio4.name == attackCell)
				{
					secondPlayer->MyEntio4.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio4.posX, secondPlayer->MyEntio4.posY, secondPlayer->MyEntio4.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio5.name == attackCell)
				{
					secondPlayer->MyEntio5.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio5.posX, secondPlayer->MyEntio5.posY, secondPlayer->MyEntio5.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else if (secondPlayer->MyEntio6.name == attackCell)
				{
					secondPlayer->MyEntio6.live = 0;
					secondPlayer->decreaseEntios();
					b.setCell(secondPlayer->MyEntio6.posX, secondPlayer->MyEntio6.posY, secondPlayer->MyEntio6.actualGround);
					std::cout << "You killed an Entio" << std::endl;
					enti::systemPause();
				}

				else
				{
					std::cout << "Attack Missed" << std::endl;
					enti::systemPause();
				}

				break;



			default:
				break;
			}

			break;

		case 2:
			std::cout << "Press 1 to attack up" << std::endl;
			std::cout << "Press 2 to attack left" << std::endl;
			std::cout << "Press 3 to attack down" << std::endl;
			std::cout << "Press 4 to attack right" << std::endl;

			std::cin >> direction;

			switch (direction)
			{
			case 1:

				for (int i = 1; i <= 10; i++)
				{
					attackCell = b.getCell(currentEntio->posX - i, currentEntio->posY);
					if (attackCell == 'X')
					{
						std::cout << "Mountain" << std::endl;
						enti::systemPause();
						break;

					}

					else if (attackCell == secondPlayer->MyEntio1.name && i >= 3)
					{
						secondPlayer->MyEntio1.live -= (11 - i);
						if (secondPlayer->MyEntio1.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}

					else if (attackCell == secondPlayer->MyEntio2.name && i >= 3)
					{
						secondPlayer->MyEntio2.live -= (11 - i);
						if (secondPlayer->MyEntio2.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio3.name && i >= 3)
					{
						secondPlayer->MyEntio3.live -= (11 - i);
						if (secondPlayer->MyEntio3.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio4.name && i >= 3)
					{
						secondPlayer->MyEntio4.live -= (11 - i);
						if (secondPlayer->MyEntio4.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio5.name && i >= 3)
					{
						secondPlayer->MyEntio5.live -= (11 - i);
						if (secondPlayer->MyEntio5.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio6.name && i >= 3)
					{
						secondPlayer->MyEntio6.live -= (11 - i);
						if (secondPlayer->MyEntio6.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else
					{
						//std::cout << "Attack Missed" << std::endl;
						//enti::systemPause();
						//break;
					}
				}

				currentEntio->arrows--;

				break;

			case 2:

				for (int i = 1; i <= 10; i++)
				{
					attackCell = b.getCell(currentEntio->posX, currentEntio->posY - i);
					if (attackCell == 'X')
					{
						std::cout << "Attack Missed" << std::endl;
						enti::systemPause();
						break;

					}

					else if (attackCell == secondPlayer->MyEntio1.name && i >= 3)
					{
						secondPlayer->MyEntio1.live -= (11 - i);
						if (secondPlayer->MyEntio1.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}

					else if (attackCell == secondPlayer->MyEntio2.name && i >= 3)
					{
						secondPlayer->MyEntio2.live -= (11 - i);
						if (secondPlayer->MyEntio2.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio3.name && i >= 3)
					{
						secondPlayer->MyEntio3.live -= (11 - i);
						if (secondPlayer->MyEntio3.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio4.name && i >= 3)
					{
						secondPlayer->MyEntio4.live -= (11 - i);
						if (secondPlayer->MyEntio4.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio5.name && i >= 3)
					{
						secondPlayer->MyEntio5.live -= (11 - i);
						if (secondPlayer->MyEntio5.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio6.name && i >= 3)
					{
						secondPlayer->MyEntio6.live -= (11 - i);
						if (secondPlayer->MyEntio6.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else
					{
						std::cout << "Attack Missed" << std::endl;
						enti::systemPause();
						break;
					}
				}

				currentEntio->arrows--;

				break;

			case 3:

				for (int i = 1; i <= 10; i++)
				{
					attackCell = b.getCell(currentEntio->posX + i, currentEntio->posY);
					if (attackCell == 'X')
					{
						std::cout << "Attack Missed" << std::endl;
						enti::systemPause();
						break;

					}

					else if (attackCell == secondPlayer->MyEntio1.name && i >= 3)
					{
						secondPlayer->MyEntio1.live -= (11 - i);
						if (secondPlayer->MyEntio1.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}

					else if (attackCell == secondPlayer->MyEntio2.name && i >= 3)
					{
						secondPlayer->MyEntio2.live -= (11 - i);
						if (secondPlayer->MyEntio2.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio3.name && i >= 3)
					{
						secondPlayer->MyEntio3.live -= (11 - i);
						if (secondPlayer->MyEntio3.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio4.name && i >= 3)
					{
						secondPlayer->MyEntio4.live -= (11 - i);
						if (secondPlayer->MyEntio4.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio5.name && i >= 3)
					{
						secondPlayer->MyEntio5.live -= (11 - i);
						if (secondPlayer->MyEntio5.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else if (attackCell == secondPlayer->MyEntio6.name && i >= 3)
					{
						secondPlayer->MyEntio6.live -= (11 - i);
						if (secondPlayer->MyEntio6.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}
					else
					{
						std::cout << "Attack Missed" << std::endl;
						enti::systemPause();
						break;
					}
				}

				currentEntio->arrows--;

				break;

			case 4:

				for (int i = 1; i <= 10; i++)
				{
					attackCell = b.getCell(currentEntio->posX, currentEntio->posY + i);
					if (attackCell == 'X')
					{
						std::cout << "Attack Missed" << std::endl;
						enti::systemPause();
						break;

					}

					else if (attackCell == secondPlayer->MyEntio1.name && i >= 3)
					{
						secondPlayer->MyEntio1.live -= (11 - i);
						if (secondPlayer->MyEntio1.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
						}
						break;
					}

					else if (attackCell == secondPlayer->MyEntio2.name && i >= 3)
					{
						secondPlayer->MyEntio2.live -= (11 - i);
						if (secondPlayer->MyEntio2.live <= 0)
						{
							secondPlayer->decreaseEntios();
							std::cout << "You killed an Entio" << std::endl;
							enti::systemPause();
							break;
						}
						else if (attackCell == secondPlayer->MyEntio3.name && i >= 3)
						{
							secondPlayer->MyEntio3.live -= (11 - i);
							if (secondPlayer->MyEntio3.live <= 0)
							{
								secondPlayer->decreaseEntios();
								std::cout << "You killed an Entio" << std::endl;
								enti::systemPause();
							}
							break;
						}
						else if (attackCell == secondPlayer->MyEntio4.name && i >= 3)
						{
							secondPlayer->MyEntio4.live -= (11 - i);
							if (secondPlayer->MyEntio4.live <= 0)
							{
								secondPlayer->decreaseEntios();
								std::cout << "You killed an Entio" << std::endl;
								enti::systemPause();
							}
							break;
						}
						else if (attackCell == secondPlayer->MyEntio5.name && i >= 3)
						{
							secondPlayer->MyEntio5.live -= (11 - i);
							if (secondPlayer->MyEntio5.live <= 0)
							{
								secondPlayer->decreaseEntios();
								std::cout << "You killed an Entio" << std::endl;
								enti::systemPause();
							}
							break;
						}
						else if (attackCell == secondPlayer->MyEntio6.name && i >= 3)
						{
							secondPlayer->MyEntio6.live -= (11 - i);
							if (secondPlayer->MyEntio6.live <= 0)
							{
								secondPlayer->decreaseEntios();
								std::cout << "You killed an Entio" << std::endl;
								enti::systemPause();
							}
							break;
						}
						else
						{
							std::cout << "Attack Missed" << std::endl;
							enti::systemPause();
							break;
						}
					}

					currentEntio->arrows--;

					break;
				}
				//currentEntio.arrows--;
				break;
			}

			currentEntio->fatigue--;
			currentPlayer->movementsDecrease();
		}

		//enti::systemPause();

		return exit;

	}


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

	
enti::InputKey gameController::waitUntilKeypressed()
{
	enti::InputKey input;
	do {
		input = enti::getInputKey();

	} while (input == enti::InputKey::NONE);

	return input;
}


gameController::~gameController()
{
}

