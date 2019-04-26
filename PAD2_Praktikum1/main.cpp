#include "MastermindDigits.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	bool gameRunning = true;
	bool menuRunning = true;
	int gameInput;
	int menuInput;
	int in;
	unsigned int digitContainer;
	MastermindDigits guess = MastermindDigits(0);
	MastermindDigits toGuess = MastermindDigits(0);

	cout << "-----\nWelcome to MasterMind!\n-----\n" << "Enter 1 to TEST, 2 to PLAY or 3 to EXIT." << endl;
	while (menuRunning)
	{
		cin >> in;
		switch (in) {
		default: cout << "Enter 1 to TEST, 2 to PLAY or 3 to EXIT." << endl;
			break;
		case 1: cout << "Enter the number you want to guess: " << endl;
			cin >> menuInput;
			toGuess = MastermindDigits(menuInput);
			digitContainer = toGuess;
			cout << digitContainer;
			break;
		case 2: cout << "Start play mode" << endl;
			toGuess.makeDigitsToGuess();
			digitContainer = toGuess;
			while (gameRunning)
			{
				cout << "Enter number: " << endl;
				cin >> gameInput;
				guess = MastermindDigits(gameInput);
				if (gameInput < 6667 && gameInput > 1110)
				{
					if (guess == toGuess)
					{
						cout << "Correct, the number was: " << digitContainer << endl;
						return 0;
					}
					else
					{
						cout << "Incorrect: " << digitContainer << endl;
					}
				}
				else
					cout << "Invalid Input" << endl;
			}
			break;
		case 3: return 0;
	}
	}
}