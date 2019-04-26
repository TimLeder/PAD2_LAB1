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
	for (int i = 0; i < 4; i++)
	{
		digits[i] = 1 + (rand() % 6);
	}
}

unsigned MastermindDigits::locationRight(MastermindDigits input)
{
	unsigned int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (digits[i] == input.digits[i])
		{
			count++;
		}
	}
	return count;
}

unsigned MastermindDigits::locationWrong(MastermindDigits input)
{
	unsigned int count = 0;
	unsigned int getLocationRight = this->locationRight(input);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (digits[i] == input.digits[j])
			{
				count++;
			}
		}
	}
	count -= getLocationRight;
	return count;
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

bool MastermindDigits::getException()
{
	for (int i = 0; i < 4; i++)
	{
		if (digits[i] > 6 || digits[i] == 0)
			return true;
	}
	return false;
}
