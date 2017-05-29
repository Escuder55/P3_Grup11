#pragma once
#include<vector>
#include<iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class battlefield
{
public:
	
	int rows{ 36 };
	int columns{74};

	char field[36][74];


	battlefield();
	char getCell(int x,int y);
	void setCell(int x, int y, char elment);
	~battlefield();
};

