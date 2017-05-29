#include "battlefield.h"



battlefield::battlefield()
{
	
	

	std::ifstream level("default.cfg");
	std::string line;

	//field[rows][columns];

	for (int i = 0; i < rows-1 ; i++)
	{
		getline(level, line);
	

		for (int j = 0; j < columns; i++)
		{
			field[i][j] = line[j];
		}
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
	/*
	for (int i = 0; i < myField.rows; i++)
	{
		for (int j = 0; j < myField.columns; j++)
		{
			std::cout << myField.field[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
}