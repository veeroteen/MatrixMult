#include "MatrixMult.h"
#include <random>
#include <ctime>
int* getRawMatrix(const size_t size)
{
	int* res = new int [size*size];
	auto log = std::time(nullptr);
	std::ofstream Flog("logA.txt", std::ios::app);
	Flog << log << std::endl;
	Flog.close();
	std::srand(log);

	for (size_t i = 0; i < size*size; i++)
	{
		res[i] = rand() % 5;
	}
	return res;
}
MatrixA* RtoA(const int* matrix, size_t size)
{
	int** result = new int*[size];
	for (size_t y = 0; y < size; y++)
	{
		int* row = new int[size];
		for (size_t x = 0; x < size; x++)
		{
			row[x] = matrix[y * size + x];
		}
		result[y] = row;
	}
	return new MatrixA(result,size);
}
MatrixAR* RtoAR(const int* matrix, size_t size)
{
	int* result = new int[size * size];

	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			result[x + y * size] = matrix[y * size + x];
		}
	}

	return new MatrixAR(result, size);

}
MatrixV* RtoV(const int* matrix, size_t size)
{
	auto* result = new std::vector<std::vector<int>*>(size);

	for (size_t y = 0; y < size; y++)
	{
		std::vector<int>* row = new std::vector<int>(size);
		for (size_t x = 0; x < size; x++)
		{
			(*row)[x] = matrix[y * size + x];
		}
		(*result)[y] = row;
	}
	return new MatrixV(result);

}

MatrixVR* RtoVR(const int* matrix, size_t size)
{
	auto result = new std::vector<int>(size * size);

	for (size_t y = 0; y < size; y++)
	{
		for (size_t x = 0; x < size; x++)
		{
			(*result)[x + y * size] = matrix[y * size + x];
		}

	}
	return new MatrixVR(result, size);

}

