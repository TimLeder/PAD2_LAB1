#include "MastermindDigits.h"
#include <math.h>

MastermindDigits::MastermindDigits(unsigned int input) //constructor for main
{
	for(int i = 3; i >= 0; i--)
	{
	digits[i] = input % 10;
		input /= 10;
	}
}

MastermindDigits::MastermindDigits(const MastermindDigits & copy) //copy constructor
{
	*this = copy;
}

MastermindDigits::~MastermindDigits() //destructor
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
		if (digits[i] == input.digits[i]) //compare each digit of _this_ array with the input object's array's corresponding digit
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
	bool array1[4] = { 0 };
	bool array2[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (digits[i] == input.digits[j] && array1[i] == 0 && array2[j] == 0) //compare each digit of _this_ array with each digit of the input object's array
			{
				count++;
				array1[i] = 1;
				array2[j] = 1;
			}
		}
	}
	count -= getLocationRight; //subtract the digits which are already in the right location
	return count;
}

void MastermindDigits::operator=(const MastermindDigits & e)
{
	for (size_t i = 0; i < 4; i++)
	{
		digits[i] = e.digits[i];
	}
}

MastermindDigits::operator unsigned int() //type conversion MastermindDigits->unsigned int
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

bool MastermindDigits::getException() //if one or more digits of _this_ object's array are not 1-6, return false
{
	for (int i = 0; i < 4; i++)
	{
		if (digits[i] > 6 || digits[i] == 0)
			return true;
	}
	return false;
}

