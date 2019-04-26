#pragma once
#include <iostream>
using namespace std;

class MastermindDigits
{
public:
	MastermindDigits(unsigned int);
	MastermindDigits(const MastermindDigits&);
	~MastermindDigits();
	void makeDigitsToGuess();
	unsigned locationRight(MastermindDigits);
	unsigned locationWrong(MastermindDigits);
	void operator= (const MastermindDigits &);
	operator unsigned int();
private:
	unsigned int* digits = new unsigned int[4];
};