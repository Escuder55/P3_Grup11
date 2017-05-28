#pragma once
#include<vector>
#include<iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdio.h>

class battlefield
{
private:
	char **field;
	int rows;
	int columns;

public:
	battlefield();
	char getCell(int x,int y);
	void setCell(int x, int y, char elment);
	~battlefield();
};

