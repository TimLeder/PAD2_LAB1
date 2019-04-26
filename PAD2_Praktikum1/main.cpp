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
	MastermindDigits player = MastermindDigits(0); //create object for player's guess
	MastermindDigits secret = MastermindDigits(0); //create object for game's secret

	cout << "-----\nWelcome to MasterMind!\n-----\n" << "Enter 1 to TEST, 2 to PLAY, 3 to SOLVE or 4 to EXIT." << endl;
	while (menuRunning)
	{
		cin >> in;
		switch (in) {
		default: cout << "Enter 1 to TEST, 2 to PLAY, 3 to SOLVE or 4 to EXIT." << endl;
			break;
		case 1: cout << "Enter the number you want to guess: ";
			cin >> menuInput;
			secret = MastermindDigits(menuInput); //overwrite secret with menu input
			if (secret.getException() || menuInput > 6666 || menuInput < 1111)
			{
				cout << "Only use digits 0-6. Only use four digits." << endl;
			}
			else
			{
				digitContainer = secret;
				while (gameRunning)
				{
					cout << "Enter number: ";
					cin >> gameInput;
					player = MastermindDigits(gameInput); //overwrite player object with new input
					if (gameInput < 6667 && gameInput > 1110 && player.getException() == false)
					{
						if (player == secret) //compare objects
						{
							cout << "Correct, the number was: " << digitContainer << endl;
							return 0; //quit game if objects are identical
						}
						else //return to loop if object is not identical
						{
							cout << "Incorrect: " << digitContainer << endl << "Correct locations: " << secret.locationRight(player)
								<< endl << "Correct digits: " << secret.locationWrong(player) << endl << endl;
						}
					}
					else
						cout << "Only use digits 0-6. Only use four digits." << endl;
				}
			}
			break;
		case 2: cout << "Start play mode" << endl;
			secret.makeDigitsToGuess(); //call random generation
			digitContainer = secret; //get int from object through unsigned type conversion
			while (gameRunning)
			{
				cout << "Enter number: ";
				cin >> gameInput;
				player = MastermindDigits(gameInput); //overwrite player object with new input
				if (gameInput < 6667 && gameInput > 1110 && player.getException() == false)
				{
					if (player == secret)
					{
						cout << "Correct, the number was: " << digitContainer << endl;
						return 0;
					}
					else
					{
						cout << endl << "Correct locations: " << secret.locationRight(player)
							<< endl << "Correct digits: " << secret.locationWrong(player) << endl << endl;;
					}
				}
				else
					cout << "Only use digits 0-6. Only use four digits." << endl;
			}
			break;
		case 3: 
			cin >> menuInput;
			secret = MastermindDigits(menuInput);
			if (secret.getException() || menuInput > 6666 || menuInput < 1111)
			{
				cout << "Only use digits 0-6. Only use four digits." << endl;
			}
			else
			{
				//TODO: Algorithm

			}
			break;

		case 4: return 0;
	}
	}
}