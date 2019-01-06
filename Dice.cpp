//This class represents a simple pair of dice

#include "Dice.h"

Dice::Dice(int nSides)
{
	sides = nSides;
	die1 = new Die(nSides);
	die2 = new Die(nSides);
}

Dice::~Dice()
{
	delete die1;
	delete die2;
}

int Dice::roll()
{
	first = die1->getNum();
	second = die2->getNum();
	return first + second;
}

bool Dice::doubles(Dice &dice)
{
	bool bo = false;
	if (die1->getValue() == die2->getValue())
		bo = true;
	return bo;
}

bool Dice::boxCars(Dice &dice)
{
	bool bo = false;
	if (die1->getValue() == die2->getValue() && die1->getValue() == 6)
		bo = true;
	return bo;
}

bool Dice::snakeEyes(Dice &dice)
{
	bool bo = false;
	if (die1->getValue() == die2->getValue() && die1->getValue() == 1)
		bo = true;
	return bo;
}

ostream &operator <<(ostream &strm, const Dice* dice)
{
	cout << dice->getDie1() << " " << dice->getDie2() << endl;
	return strm;
}
