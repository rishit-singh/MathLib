#ifndef GENERAL_H

#include <math.h>
#include "constants.h"

namespace MathLib
{
	class General	//	Common math functions.
	{
	public:
		static int Factorial(int x)	//	Calculates the factorial of the provided int recursively.
		{
			return (!x)	? 1 : (x * General::Factorial(x - 1));
		}

		static double GetRadians(double angle)	//	Converts the angle provided in degrees to radians.
		{
			return (angle * (PI / 180));
		}

		static double Sin(double angle)		//	Calculates the sine of the angle provided in degrees.
		{
			double result = 0;

			angle = General::GetRadians(angle);

			for (int x = 0; x < TAYLOR_PRECISION; x++)
				result += ((pow(-1, x) * pow(angle, (2 * x) + 1)) / General::Factorial((2 * x) + 1));

			return result;
		}
	};
}

#endif