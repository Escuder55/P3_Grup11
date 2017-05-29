#pragma once
#include<vector>
#include<iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Renderer.hh"

#define rowsSize 36
#define columnsSize 74
class battlefield
{
public:
	
	int rows{ rowsSize };
	int columns{columnsSize};

	char field[rowsSize][columnsSize];


	battlefield();
	char getCell(int x,int y);
	void setCell(int x, int y, char elment);
	~battlefield();
};

