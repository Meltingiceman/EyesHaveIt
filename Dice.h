#pragma once
#ifndef DICE_H
#define DICE_H
#include "Die.h"
using namespace std;

class Dice;

ostream &operator << (ostream &, const Dice *);

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
	int getDie1() const
	{
		return die1->getValue();
	}
	int getDie2() const
	{
		return die2->getValue();
	}
	bool boxCars(Dice &);
	bool snakeEyes(Dice &);
	bool doubles(Dice &);
	
	friend ostream &operator << (ostream &, const Dice *);

};

#endif
