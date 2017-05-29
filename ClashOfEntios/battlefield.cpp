#include "battlefield.h"



battlefield::battlefield()
{
	
	
	{
		std::ifstream level("default.cfg"); 
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