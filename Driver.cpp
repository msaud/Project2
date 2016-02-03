#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include "Game.h"
using namespace std;

int main()
{

	int NumOfPlaye;	
	do
	{
	if (NumOfPlaye > 6)
		cout << "\nThe maximum players is 5\n";

	cout << "Please Enter the number of players: ";
	cin >> NumOfPlaye;
	
	}
	while (NumOfPlaye > 6);
	
	Game* Chicken = new Game(NumOfPlaye);

	Chicken->RunGame();

//	system("clear && printf '\e[3J'");

	return 0;
}
