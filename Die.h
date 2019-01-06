#pragma once
#ifndef DIE_H
#define DIE_H
#include <cmath>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Die
{
private:
	int max;
	int min;
	int value;
public:
	Die(int in)
	{
		srand(time(0));
		max = in;
		min = 1;
	}

	Die(int in1, int in2)
	{
		srand(time(0));
		max = in1;
		min = in2;
	}

	int getNum()
	{
		value = rand() % (max - min + 1) + min;
		return value;
	}

	int getValue()
	{
		return value;
	}
};

#endif
