#pragma once
#ifndef EYESHAVEIT_H
#define EYESHAVEIT_H
#include "Dice.h"
using namespace std;

class EyesHaveIt
{
private:
	Dice *dice;

	int compScore;
	int humScore;
	int turnScore;
	int multiplier;

	bool humTurn;
	bool endTurn;
	
	string name;
	
	char userChoice;

public:
	EyesHaveIt(string &uName, int sides)
	{
		dice = new Dice(sides);
		
		compScore = 0;
		humScore = 0;
		turnScore = 0;
		multiplier = 0;
		
		endTurn = false;

		name = uName;

		coinToss();
		userChoice = 'Y';
		
	}
	~EyesHaveIt()
	{
		delete dice;
	}
	void playGame();
	void doTurns(int);
	void comp(); //computer's turn
	void hum(); //human's turn
	void tieBreaker();
	void outro();
	void doubleChecker();
	void getInput();
	void multiply();
	void coinToss();
};
#endif