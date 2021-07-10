#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sin.h"

double GetFactorial(int n)
{
	return (n == 0) ? 1 : (n * GetFactorial(n - 1));
}

double GetRadians(double angle)
{
	return (angle * (PI / 180));
}

double Sin(double angle)
{	
	double sinResult = 0;

	angle = GetRadians(angle);
	
	for (int x = 0; x < PRECISION; x++)
		sinResult += ((pow(-1, x) * pow(angle, (2 * x) + 1) / GetFactorial((2 * x) + 1)));

	return sinResult;
}

int main(int argc, char** argv)
{	
	double number = atof(argv[1]);

	std::cout << "Sin " << number << ": " << Sin(number) << '\n';

	return 0;
}


