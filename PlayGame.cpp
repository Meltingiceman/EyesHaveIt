#include "EyesHaveIt.h"
#include <iomanip>
using namespace std;

int main()
{
	int sides;
	string name;
	
	cout << "Enter the name of the player: ";
	getline(cin, name);
	
	cout << "How many sides do you want on your dice: ";
	cin >> sides;

	EyesHaveIt *game = new EyesHaveIt(name, sides);
	game->playGame();

	system("pause"); //so I could see the output with my IDE
	delete game;
	
	return 0;
}