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
	MathLib::Matrix<int, 2, 2> matrix = MathLib::Matrix<int, 2, 2>(
		new int[4] {
			3, 7,
			5, 8
		}, 4);
	
	PrintMatrix<int>(matrix.Transpose());

	return 0;
}
