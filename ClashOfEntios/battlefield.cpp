#include "battlefield.h"



battlefield::battlefield()
{
	
	

	//std::ifstream level("default.cfg");
	//std::string line;

	////field[rows][columns];
	//if (level.is_open())
	//{
	//	for (int i = 0; i < rows ; i++)
	//	{
	//		getline(level, line);

	//		for (int j = 0; j < line.size(); i++)
	//		{
	//			field[i][j] = line[j];
	//		}
	//	}
	//}
	//else
	//{
	//	std::cout << "The file can't been opened!!" << std::endl;
	//}
	//level.close();		
	{
		std::ifstream level("default.cfg"); //Creo mi archivo file de tipo ifstream en el que cargo el contenido del documento default.cfg (el campo de juego)
		std::string line;

		if (level.is_open())
		{
			int counter = 0;

			while (getline(level, line))
			{
				for (int i = 0; i < line.size(); i++)
				{
					field[counter][i] = line[i];					
				}
				counter++;
			}
			level.close();
		}
		else std::cout << "It's not possible to find the file you've just tried to open" << std::endl;
	}

}

char battlefield::getCell(int x, int y)
{
	return field[x][y];
}
void battlefield::setCell(int x, int y, char element)
{
	field[x][y] = element;
}


battlefield::~battlefield()
{
}


void main()
{
	battlefield myField;
	
	for (int i = 0; i < myField.rows; i++)
	{
		for (int j = 0; j < myField.columns; j++)
		{
			
			std::cout << myField.field[i][j] << std::flush;
		}
		std::cout << std::endl;
	}
}