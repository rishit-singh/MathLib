#ifndef MATRIX_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tools.h"

namespace MathLib
{
	template<typename T, int rows, int columns>
	class Matrix
	{
		bool Fill(T value, unsigned int index)	//	Sets the value of elements of the MatrixArray starting from the provided index to the specified value.
		{
			if (index >= this->Size)
				return false; 

			std::cout << "size: " << this->Size << '\n'; 

			int x = 0;

			for (x = index; x < this->Size; x++)
				this->MatrixArray[x] = value;

			return true;
		}

		bool Initialize()	//	Initializes a null matrix
		{
			this->Fill(NULL, 0);
		}

		bool Initialize(T* matrixArray, int size)	//	Copies the provided initial array to the Matrix array.
		{
			if (size > this->Size)
				return false;

			Tools::CopyArray(this->MatrixArray, matrixArray, size);

			this->Fill(NULL, size);

			return true;
		}

		bool Initialize(std::vector<T> matrixArray)	//	Copies the provided initial array to the Matrix array.
		{
			int size = matrixArray.size();

			if (size > this->Size)
				return false;

			Tools::CopyArray(this->MatrixArray, matrixArray.data(), size);

			this->Fill(NULL, size);

			return true;
		}

	public:
		T MatrixArray[rows * columns] {};	//	Array storing the mapped matrix.

		unsigned int Size,	//	Size of the Matrix Array
					Rows,
					Columns;


		template<int x, int y>
		bool IsMultiplicable(Matrix<T, x, y> matrix)	//	Checks if the current instance is multiplicable with the provided instance
		{
			return (matrix.Rows == this->Columns || matrix.Columns == this->Rows);
		}

		void Add(T value)
		{
			for (int x = 0; x < this->Size; x++)
				this->MatrixArray[x] += value;
		}
		
		Matrix<T, rows, columns> Add(Matrix<T, rows, columns> matrix)
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();

			for (int x = 0; x < this->Size; x++)
				*TempMatrix.GetElementPointer(x) += matrix.MatrixArray[x];

			return TempMatrix;
		}
	
		Matrix<T, rows, columns> Subtract(T value)
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();

			for (int x = 0; x < this->Size; x++)
				TempMatrix.MatrixArray[x] = this->MatrixArray[x] - value;

			return TempMatrix;
		}
		
		Matrix<T, rows, columns> Subtract(Matrix<T, rows, columns> matrix)
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();

			for (int x = 0; x < this->Size; x++)
				TempMatrix.MatrixArray[x] = this->MatrixArray[x] - matrix.MatrixArray[x];
			
			return TempMatrix;
		}

		Matrix<T, rows, columns> Multiply(T value)
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();

			for (int x = 0; x < this->Size; x++)	
				TempMatrix.MatrixArray[x] = value * this->MatrixArray[x];

			return TempMatrix;
		}
		
		Matrix<T, rows, columns> Multiply(Matrix<T, rows, columns> matrix)
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();
			
			if (!this->IsMultiplicable(matrix))
				return TempMatrix;

			for (int x = 0; x < this->Rows; x++)
			{
				for (int y = 0; y < matrix.Columns; y++)
				{	
					*TempMatrix.GetElementPointer(x, y) = 0;

					for	(int z = 0; z < this->Columns; z++)		
						*TempMatrix.GetElementPointer(x, y) += (this->GetValue(x, z) * matrix.GetValue(z, y));
				}
			}

			return TempMatrix;
		}

		T* GetElementPointer(unsigned int i, unsigned int j)
		{
			if (i >= rows || j >= columns)
				return nullptr;

			return &this->MatrixArray[(i * rows) + j];
		}

		T GetValue(unsigned int i, unsigned int j)	//	Returns the element of the matrix at the provided indices.
		{
			if (i >= rows || j >= columns)
				return -1;

			return this->MatrixArray[(i * rows) + j];
		}

		Matrix<T, rows, columns> Transpose()
		{
			Matrix<T, rows, columns> TempMatrix = Matrix<T, rows, columns>();

			for (int x = 0; x < this->Rows; x++)
				for (int y = 0; y < this->Columns; y++)
					*TempMatrix.GetElementPointer(y, x) = this->GetValue(x, y);

			return TempMatrix;
		}

		Matrix<T, rows, columns> operator +(Matrix<T, rows, columns>const& matrix)
		{
			return this->Add(matrix);
		}			
		
		Matrix<T, rows, columns> operator -(Matrix<T, rows, columns>const& matrix)
		{
			return this->Subtract(matrix);
		}
		
		Matrix<T, rows, columns> operator *(Matrix<T, rows, columns>const& rMatrix)
		{
			return this->Multiply(rMatrix);
		}

		Matrix() : Rows(rows), Columns(columns), Size(rows * columns)
		{
			// this->MatrixArray = new T[this->Size] {};
		}

		Matrix(T* matrixArray, unsigned int size) : Rows(rows), Columns(columns), Size(rows * columns)
		{
			// this->MatrixArray = new T[this->Size];

			this->Initialize(matrixArray, size);
		}

		Matrix(std::vector<T> matrixArray) : Rows(rows), Columns(columns), Size(rows * columns)
		{
			this->MatrixArray = new T[this->Size];
			// 
			this->Initialize(matrixArray);
		}

		~Matrix()
		{
		}
	};
}

#endif
