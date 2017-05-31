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
		else std::cout << "The file is not open." << std::endl;
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

/*
void main()
{
	battlefield myField;
	
	for (int i = 0; i < myField.rows; i++)
	{
		for (int j = 0; j < myField.columns - 1; j++)
		{
			if (myField.field[i][j] == 'X')
			{
				enti::cout <<enti::Color :: RED << 'X' << " ";
			}
			
			else if (myField.field[i][j] == 'O')
			{
				enti::cout << enti::Color::CYAN << myField.field[i][j] << " ";

			}

			else if (myField.field[i][j] == ':')
			{
				enti::cout << enti::Color:: GREEN << myField.field[i][j] << " ";
			}
			else if (myField.field[i][j] == '.')
			{
				enti::cout << enti::Color::BROWN << myField.field[i][j] << " ";
			}
			else if (myField.field[i][j] >= '0' || myField.field[i][j] <= '6')
			{
				enti::cout << enti :: Color :: MAGENTA << myField.field[i][j] << " ";
			}
			std::cout << " ";
		 
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
}*/
	