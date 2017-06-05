#include "battlefield.h"
#include "Player.h"
#include "gameController.h"
#include <Windows.h>
#include <iostream>

void printMap(battlefield myField, Player::Entio *currentEntio)
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
		enti::cout << currentEntio->posY << "/" << currentEntio->posX << enti::endl;
	}
	
	enti::cout << enti::cend;
	
}

void main()
{
	
	battlefield myBattleField;
	
	Player myPlayer(1, myBattleField);
	Player myPlayer2(2, myBattleField);
	gameController myGameController(myPlayer, myBattleField, myPlayer2);

	Player *activePlayer = &myPlayer2;
	Player *waitingPlayer = &myPlayer;

	Player::Entio *currentEntio = &activePlayer->MyEntio1;
	printMap(myBattleField, currentEntio);

	//std::cout << myBattleField.field[currentEntio->posX-3][currentEntio->posY] << std::endl;
	//system("pause");
	bool exitGame = false;
	while ( exitGame == false )
	{
		printMap(myBattleField,currentEntio);

		exitGame=myGameController.updateGame(currentEntio,myBattleField,activePlayer, waitingPlayer);
		
		if (waitingPlayer->numberOfEntios <= 0)
		{
			exitGame = true;
		}
		
		
		
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