#include <iostream>
#include "matrix.h"

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
	MathLib::Matrix<int, 3, 3> matrix = MathLib::Matrix<int, 3, 3>(
		new int[9] {
			3, 7, 2,
			5, 8, 7,
			1, 2, 3
		}, 9);
	
	PrintMatrix<int>(matrix.Transpose());

	return 0;
}
