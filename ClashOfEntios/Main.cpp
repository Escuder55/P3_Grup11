#include "battlefield.h"
#include "Player.h"
#include "gameController.h"
#include <Windows.h>

void printMap(battlefield myField)
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
	enti::cout << enti::cend;
}

void main()
{
	
	battlefield myBattleField;
	printMap(myBattleField);
	Player myPlayer(1, myBattleField);
	Player myPlayer2(2, myBattleField);
	gameController myGameController(myPlayer, myBattleField, myPlayer2);

	

	while (myPlayer2.numberOfEntios > 0)
	{
		myGameController.updateGame(myPlayer.MyEntio1,myBattleField,myPlayer, myPlayer2);
		//system("cls");
		printMap(myBattleField);
		//std::cout << myPlayer.MyEntio1.posX << "/" << myPlayer.MyEntio1.posY;
	}

	std::cout << "YOU WIN!!" << std::endl;
}