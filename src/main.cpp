#include <iostream>
#include "matrix.h"
#include "general.h"

template<typename T, int rows, int columns>
static void PrintMatrix(MathLib::Matrix<T, rows, columns> matrix)
{
	for (int x = 0; x < matrix.Rows; x++)
	{
		for (int y = 0; y < matrix.Columns; y++)
			std::cout << matrix.GetValue(x, y)	<< ' ';

		std::cout << '\n';
	}
}

int main()
{
	int* numbers = new int[5] { 0, 30, 45, 60, 90 };


	for (int x = 0; x < 5; x++)
		std::cout << "Sin(" << numbers[x] << "): " << MathLib::General::Sin(numbers[x])
			<< '\n';
	
	delete numbers;

	return 0;
}
