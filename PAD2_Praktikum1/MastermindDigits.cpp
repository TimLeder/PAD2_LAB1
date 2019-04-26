#include "MastermindDigits.h"
#include <math.h>

MastermindDigits::MastermindDigits(unsigned int input)
{
	for(int i = 3; i >= 0; i--)
	{
	digits[i] = input % 10;
		input /= 10;
	}
}

MastermindDigits::MastermindDigits(const MastermindDigits & copy)
{
	*this = copy;
}

MastermindDigits::~MastermindDigits()
{
	delete[] digits;
}

void MastermindDigits::makeDigitsToGuess()
{
	unsigned int guess;
	unsigned int one = rand() % 6 + 1;
	unsigned int two = 10 * rand() % 6 + 1;
	unsigned int three = 100 * rand() % 6 + 1;
	unsigned int four = 1000 * rand() % 6 + 1;
	*this = MastermindDigits(guess);
}

unsigned MastermindDigits::locationRight(MastermindDigits input)
{
	return 0;
}

unsigned MastermindDigits::locationWrong(MastermindDigits input)
{
	return 0;
}

void MastermindDigits::operator=(const MastermindDigits & e)
{
	for (size_t i = 0; i < 4; i++)
	{
		digits[i] = e.digits[i];
	}
}

MastermindDigits::operator unsigned int()
{
	unsigned int out = 0;
	unsigned int factor = 1000;
	unsigned int temp = 0;
	for (size_t i = 0; i < 4; i++)
	{
		temp = digits[i];
		temp *= factor;
		factor /= 10;
		out += temp;
	}
	return out;
}
