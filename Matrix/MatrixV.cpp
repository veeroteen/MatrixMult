#include "MatrixMult.h"

MatrixV::MatrixV(std::vector<std::vector<int>*>* _matrix)
{
	matrix = _matrix;
}
MatrixV::~MatrixV()
{
	if (matrix != nullptr)
	{
		for (size_t i = 0; i < matrix->size(); i++) 
		{
			if ((*matrix)[i] != nullptr)
			{
				delete (*matrix)[i];
			}
		}
		delete matrix;
	}
}
MatrixV* MatrixV::getTransposed() const
{
	auto result = new std::vector<std::vector<int>*>(matrix->size());

	for (size_t y = 0; y < matrix->size(); y++)
	{
		std::vector<int>* row = new std::vector<int>(matrix->size());
		for (size_t x = 0; x < matrix->size(); x++)
		{
			(*row)[x] = (*(*matrix)[x])[y];
		}
		(*result)[y] = row;
	}

	return new MatrixV(result);
}

MatrixV* MatrixV::multiply(const MatrixV& b) const
{
	auto result = new std::vector<std::vector<int>*>(matrix->size());

	for (int y = 0; y < matrix->size(); y++)
	{
		std::vector<int>* row = new std::vector<int>(matrix->size());
		for (int x = 0; x < matrix->size(); x++)
		{
			int accum = 0;
			for (int n = 0; n < matrix->size(); n++)
			{
				accum += (*(*matrix)[y])[n] * (*(*b.matrix)[n])[x];
			}
			(*row)[x] = accum;
		}
		(*result)[y] = row;
	}

#ifdef DEBUG
	for (int y = 0; y < result->size(); y++)
	{
		for (int x = 0; x < result->size(); x++)
		{
			std::cout << (*(*result)[y])[x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return new MatrixV(result);
}
MatrixV* MatrixV::multiplyT(const MatrixV& b) const
{
	auto result = new std::vector<std::vector<int>*>(matrix->size());
	for (int y = 0; y < matrix->size(); y++)
	{
		std::vector<int>* row = new std::vector<int>(matrix->size());
		for (int x = 0; x < matrix->size(); x++)
		{
			int accum = 0;
			for (int n = 0; n < matrix->size(); n++)
			{
				accum += (*(*matrix)[y])[n] * (*(*b.matrix)[x])[n];
			}
			(*row)[x] = accum;

		}
		(*result)[y] = row;
	}

#ifdef DEBUG
	for (int y = 0; y < result->size(); y++)
	{
		for (int x = 0; x < result->size(); x++)
		{
			std::cout << (*(*result)[y])[x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return new MatrixV(result);
}

void MatrixV::multiply(const MatrixV& b, std::vector<std::vector<int>*> *result) const
{
	for (int y = 0; y < matrix->size(); y++)
	{
		std::vector<int>* row = new std::vector<int>(matrix->size());
		for (int x = 0; x < matrix->size(); x++)
		{
			int accum = 0;
			for (int n = 0; n < matrix->size(); n++)
			{
				accum += (*(*matrix)[y])[n] * (*(*b.matrix)[n])[x];
			}
			(*row)[x] = accum;
		}
		(*result)[y] = row;
	}

#ifdef DEBUG
	for (int y = 0; y < result->size(); y++)
	{
		for (int x = 0; x < result->size(); x++)
		{
			std::cout << (*(*result)[y])[x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return;
}

void MatrixV::multiplyT(const MatrixV& b, std::vector<std::vector<int>*>* result) const
{
	for (int y = 0; y < matrix->size(); y++)
	{
		std::vector<int>* row = new std::vector<int>(matrix->size());
		for (int x = 0; x < matrix->size(); x++)
		{
			int accum = 0;
			for (int n = 0; n < matrix->size(); n++)
			{
				accum += (*(*matrix)[y])[n] * (*(*b.matrix)[x])[n];
			}
			(*row)[x] = accum;

		}
		(*result)[y] = row;
	}

#ifdef DEBUG
	for (int y = 0; y < result->size(); y++)
	{
		for (int x = 0; x < result->size(); x++)
		{
			std::cout << (*(*result)[y])[x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	return;
}