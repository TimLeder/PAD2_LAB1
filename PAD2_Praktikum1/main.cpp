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
		case 1: cout << "Enter the number you want to guess: ";
			cin >> menuInput;
			toGuess = MastermindDigits(menuInput);
			if (toGuess.getException() || menuInput > 6666 || menuInput < 1111)
			{
				cout << "Only use digits 0-6. Only use four digits." << endl;
			}
			else
			{
				digitContainer = toGuess;
				while (gameRunning)
				{
					cout << "Enter number: ";
					cin >> gameInput;
					guess = MastermindDigits(gameInput);
					if (gameInput < 6667 && gameInput > 1110 && guess.getException() == false)
					{
						if (guess == toGuess)
						{
							cout << "Correct, the number was: " << digitContainer << endl;
							return 0;
						}
						else
						{
							cout << "Incorrect: " << digitContainer << endl << "Correct locations: " << toGuess.locationRight(guess)
								<< endl << "Correct digits: " << toGuess.locationWrong(guess) << endl << endl;
						}
					}
					else
						cout << "Only use digits 0-6. Only use four digits." << endl;
				}
			}
			break;
		case 2: cout << "Start play mode" << endl;
			toGuess.makeDigitsToGuess();
			digitContainer = toGuess;
			while (gameRunning)
			{
				cout << "Enter number: ";
				cin >> gameInput;
				guess = MastermindDigits(gameInput);
				if (gameInput < 6667 && gameInput > 1110 && guess.getException() == false)
				{
					if (guess == toGuess)
					{
						cout << "Correct, the number was: " << digitContainer << endl;
						return 0;
					}
					else
					{
						cout << endl << "Correct locations: " << toGuess.locationRight(guess)
							<< endl << "Correct digits: " << toGuess.locationWrong(guess) << endl << endl;;
					}
				}
				else
					cout << "Only use digits 0-6. Only use four digits." << endl;
			}
			break;
		case 3: return 0;
	}
	}
}