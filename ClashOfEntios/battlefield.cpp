#include "battlefield.h"



battlefield::battlefield()
{
	rows = 74;
	columns = 36;
	field = new char *[rows];

	for (int i = 0; i < rows; i++)
	{
		field[i] = new char[columns];
	}
	

	//std::ifstream level("default.cfg");
	FILE *level;
	fopen("default.cfg", "r");

		for (int i = 0; i <= rows; i++)
		{
			for (int j = 0; j < columns; i++)
			{
				field[i][j] = fgetc(level);				
			}
		}
		 
		fclose(level);


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
