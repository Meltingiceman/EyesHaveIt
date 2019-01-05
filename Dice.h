#pragma once
#ifndef DICE_H
#define DICE_H
#include "Die.h"

class Dice
{
private:
	int sides;
	int first;
	int second;
	Die *die1;
	Die *die2;

public:
	Dice(int);
	~Dice();
	int roll();
	int getDie1()
	{
		return die1->getValue();
	}
	int getDie2()
	{
		return die2->getValue();
	}
	bool boxCars(Dice &);
	bool snakeEyes(Dice &);
	bool doubles(Dice &);
	
};

#endif