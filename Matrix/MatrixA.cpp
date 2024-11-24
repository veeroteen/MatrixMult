#include "MatrixMult.h"

MatrixA::MatrixA(int** _matrix, size_t _size)
{
	size = _size;
	matrix = _matrix;
}

MatrixA::~MatrixA()
{
	if (matrix != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (matrix[i] != nullptr)
			{
				delete[] matrix[i];
			}
		}
		delete[] matrix;
	}
}


MatrixA* MatrixA::getTransposed() const
{
	int** result = new int* [size];

	for (size_t y = 0; y < size; y++)
	{
		int* row = new int[size];
		for (size_t x = 0; x < size; x++)
		{
			row[x] = matrix[x][y];
		}
		result[y] = row;
	}

	return new MatrixA(result, size);
}

MatrixA* MatrixA::multiply(const MatrixA& b) const
{
	int** result = new int* [size];

	for (size_t y = 0; y < size; y++)
	{
		int* row = new int[size];
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y][n] * b.matrix[n][x];
			}
			row[x] = accum;
		}
		result[y] = row;
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y][x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return new MatrixA(result, size);
}
MatrixA* MatrixA::multiplyT(const MatrixA& b) const
{
	int** result = new int* [size];

	for (size_t y = 0; y < size; y++)
	{
		int* row = new int[size];
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y][n] * b.matrix[x][n];
			}
			row[x] = accum;
		}
		result[y] = row;
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y][x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return new MatrixA(result, size);
}
