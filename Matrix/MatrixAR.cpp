#include "MatrixMult.h"

MatrixAR::MatrixAR(int* _matrix, size_t _size)
{
	size = _size;
	matrix = _matrix;
}

MatrixAR::~MatrixAR()
{
	if (matrix != nullptr)
	{
		delete[] matrix;
	}
}

MatrixAR* MatrixAR::getTransposed() const
{
	int* result = new int[size * size];

	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			result[size * x + y] = matrix[size * y + x];
		}
	}

	return new MatrixAR(result, size);
}

MatrixAR* MatrixAR::multiply(const MatrixAR& b) const
{
	int* result = new int[size * size];
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y * size + n] * b.matrix[n * size + x];
			}
			result[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixAR(result, size);
}

MatrixAR* MatrixAR::multiplyT(const MatrixAR& b) const
{
	int* result = new int[size * size];
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y * size + n] * b.matrix[x * size + n];
			}
			result[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixAR(result, size);
}


MatrixAR* MatrixAR::multiply(const MatrixAR& b,int* result) const
{
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y * size + n] * b.matrix[n * size + x];
			}
			result[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixAR(result, size);
}

MatrixAR* MatrixAR::multiplyT(const MatrixAR& b, int* result) const
{
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += matrix[y * size + n] * b.matrix[x * size + n];
			}
			result[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << result[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixAR(result, size);


}