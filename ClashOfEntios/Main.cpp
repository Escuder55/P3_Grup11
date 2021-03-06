#include "battlefield.h"
#include "Player.h"
#include "gameController.h"
#include <Windows.h>
#include <iostream>

void printMap(battlefield myField, Player::Entio *currentEntio, Player *currentPlayer)
{
	for (int i = 0; i < myField.rows; i++)
	{
		for (int j = 0; j < myField.columns - 1; j++)
		{
			if (myField.field[i][j] == 'X')
			{
				enti::cout << enti::Color::RED << 'X' << " ";
			}

			else if (myField.field[i][j] == 'O')
			{
				enti::cout << enti::Color::CYAN << myField.field[i][j] << " ";

			}

			else if (myField.field[i][j] == ':')
			{
				enti::cout << enti::Color::GREEN << myField.field[i][j] << " ";
			}
			else if (myField.field[i][j] == '.')
			{
				enti::cout << enti::Color::BROWN << myField.field[i][j] << " ";
			}
			else if (myField.field[i][j] >= '0' || myField.field[i][j] <= '6')
			{
				enti::cout << enti::Color::MAGENTA << myField.field[i][j] << " ";
			}
			std::cout << " ";

		}
		enti::cout << enti::endl;
	}
	
	enti::cout << enti::Color::BLUE<< "Player "<< currentPlayer->numPlayer << enti::endl;
	enti::cout << enti::Color::LIGHTGRAY << "Active Entio: " << currentEntio->name << enti::endl;
	enti::cout << enti::Color::GREEN << "Movements: " << currentPlayer->movements;
	enti::cout << enti::cend;
	std::cout << std::endl;
	
}

void main()
{
	
	battlefield myBattleField;
	
	Player myPlayer(1, myBattleField);
	Player myPlayer2(2, myBattleField);
	gameController myGameController(myPlayer, myBattleField, myPlayer2);

	Player *activePlayer = &myPlayer;
	

	Player *waitingPlayer = &myPlayer2;
	


	Player::Entio *currentEntio = new Player::Entio;
	currentEntio = &myPlayer.MyEntio1;
	
	int lastX,
		lastY,
		turn = 1,
		counter = 0;

	
	bool exitGame = false;
	while ( exitGame == false )
	{
		printMap(myBattleField,currentEntio,activePlayer);

		exitGame=myGameController.updateGame(currentEntio, myBattleField, activePlayer, waitingPlayer,lastX,lastY,turn, counter);
		
		if (waitingPlayer->numberOfEntios <= 0)
		{
			exitGame = true;
		}
		
		if (turn == 1)
		{
			activePlayer = &myPlayer;
			waitingPlayer = &myPlayer2;
		}
		else if (turn == 2)
		{
			activePlayer = &myPlayer2;
			waitingPlayer = &myPlayer;
		}
		
		//enti::cout << enti::cend;

	}
	if (waitingPlayer->numberOfEntios <= 0)
	{
		std::cout << "YOU WIN!!" << std::endl;
		system("pause");
	}
	else
	{
		std::cout << "You exit the game!! "<< std::endl;
	}
}