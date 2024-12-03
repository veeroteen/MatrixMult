#include "MatrixMult.h"


MatrixVR::MatrixVR(std::vector <int>* _matrix, size_t _size)
{
	matrix = _matrix;
	size = _size;
}

MatrixVR::~MatrixVR()
{
	if(matrix != nullptr)
	{
		delete matrix;
	}
}

MatrixVR* MatrixVR::getTransposed() const
{
	auto result = new std::vector<int>(size * size);
	for(size_t y = 0; y < size; y++)
	{
		for(size_t x = 0; x < size; x++)
		{
			(*result)[size * x + y] = (*matrix)[size * y + x];
		}
	}
	return new MatrixVR(result, size);
}
MatrixVR* MatrixVR::multiply(const MatrixVR& b) const
{
	auto result = new std::vector<int>(size * size);
	for(size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += (*matrix)[y*size + n] * (*b.matrix)[n*size +x];
			}
			(*result)[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << (*result)[y*size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixVR(result, size);

}
MatrixVR* MatrixVR::multiplyT(const MatrixVR& b) const
{
	auto result = new std::vector<int>(size * size);
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += (*matrix)[y * size + n] * (*b.matrix)[x * size + n];
			}
			(*result)[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << (*result)[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return new MatrixVR(result, size);

}

void MatrixVR::multiply(const MatrixVR& b, std::vector<int>* result) const
{
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += (*matrix)[y * size + n] * (*b.matrix)[n * size + x];
			}
			(*result)[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << (*result)[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return;

}
void MatrixVR::multiplyT(const MatrixVR& b, std::vector<int>* result) const
{
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			int accum = 0;
			for (size_t n = 0; n < size; n++)
			{
				accum += (*matrix)[y * size + n] * (*b.matrix)[x * size + n];
			}
			(*result)[y * size + x] = accum;
		}
	}

#ifdef DEBUG
	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			std::cout << (*result)[y * size + x] << " ";
		}
		std::cout << std::endl;
	}
#endif
	return;

}