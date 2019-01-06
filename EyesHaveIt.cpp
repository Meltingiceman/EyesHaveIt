#include "EyesHaveIt.h"
#include <cctype>
using namespace std;

const int ROUNDS = 6;
const int MAX_SCORE = 150;

void EyesHaveIt::playGame()
{
	while (compScore < MAX_SCORE && humScore < MAX_SCORE)
	{
		doTurns(ROUNDS);
		cout << endl;
	}
	if (compScore == humScore)
		tieBreaker(); 
	outro();
}

void EyesHaveIt::doTurns(int rounds)
{
	if (humTurn)
	{			
		hum();
		comp();
	}
	else
	{
		comp();
		hum();
	}
}

void EyesHaveIt::hum() //human's turn
{
	cout << "\t" << name << "'s turn\n----------------------------" << endl;
	int i = 0;
	userChoice = 'Y';

	while (i++ < ROUNDS && !endTurn && toupper(userChoice) == 'Y')
	{
		turnScore += dice->roll();
		cout << "Rolled: " << dice;
		doubleChecker();
		if (!endTurn && i < ROUNDS)
		{
			cout << "Current Score: " << turnScore << endl;
			getInput();
		}
	}
	
	endTurn = humTurn = false;

	multiply();
	humScore += turnScore;
	multiplier = turnScore = 0;
	
	cout << "CURRENT GAME SCORE: Computer:  " << compScore << "  " << name << ":  " << humScore << endl;
	system("pause");
	cout << endl;
}

void EyesHaveIt::comp() //computer's turn
{
	cout << "\tComputer's turn\n----------------------------" << endl;
	int i = 0;
	while (i++ < ROUNDS && turnScore < 20 && !endTurn)
	{
		turnScore += dice->roll();
		cout << "Rolled: " << dice;
	    doubleChecker();
	}
	humTurn = true;
	endTurn = false;

	multiply();
	compScore += turnScore;
	multiplier = turnScore = 0;
	
	cout << "CURRENT GAME SCORE: Computer:  " << compScore << "  " << name << ":  " << humScore << endl;
	system("pause");
	cout << endl;
}

void EyesHaveIt::doubleChecker()
{
	if (dice->boxCars(*dice))
	{
		turnScore = 0;
		cout << "Rolled box cars! All points are gone now!\n";
		if (humTurn)
			humScore = 0;
		else
			compScore = 0;
		endTurn = true;
	}
	else if (dice->snakeEyes(*dice))
	{
		cout << "Rolled snake eyes! All turn points will be doubled.\n";
		multiplier++;
	}
	else if (dice->doubles(*dice))
	{
		cout << "Rolled double... lose all turn points.\n";
		turnScore = 0;
		endTurn = true;
	}
}

void EyesHaveIt::multiply()
{
	int i = 0;
	while (i++ < multiplier)
	{
		turnScore *= 2;
	}
}

void EyesHaveIt::getInput()
{
	cout << "Roll again? (y/n) ";
	cin.ignore();
	cin >> user;
	while (user.length() != 1 || toupper(user[0]) != 'Y' && toupper(user[0]) != 'N')
	{
		if (user.length() != 1)
		{
			cout << "Enter a character: ";
			cin >> user;
		}
		else if (toupper(user[0]) != 'Y' && toupper(user[0]) != 'N')
		{
			cout << "Answer Y or N: ";
			cin >> user;
		}
	}
	/*while (toupper(user[0]) != 'Y' && toupper(user[0]) != 'N')
	{
		//cin.ignore();
		cout << "Answer: Y or N ";
		cin >> user;
	}*/
	userChoice = user[0];
}

void EyesHaveIt::outro()
{
	if (compScore > humScore)
		cout << "Sorry " << name << " you got beat by the computer!\n";
	else
		cout << name << ", Congratulations! You beat the computer!\n";
}

void EyesHaveIt::tieBreaker()
{
	while (compScore == humScore)
	{
		doTurns(ROUNDS);
	}
}

void EyesHaveIt::coinToss()
{
	humTurn = rand() % 2;
	if (humTurn)
		cout << name << " has won the coin toss and will go first.\n\n";
	else
		cout << "The computer has won the coin toss and will go first.\n\n";
}
