#pragma once
#include <iostream>
#include <vector>
#include <fstream>

//#define DEBUG

class MatrixA // R^2 arr
{
public:
	int** matrix = nullptr;
	size_t size = 0;

	MatrixA(int** _matrix, size_t _size);
	MatrixA() = default;
	~MatrixA();

	MatrixA* getTransposed() const;
	MatrixA* multiply(const MatrixA& b) const;
	MatrixA* multiplyT(const MatrixA& b) const;
	void multiply(const MatrixA& b, int** result) const;
	void multiplyT(const MatrixA& b, int** result) const;
};

class MatrixAR // R arr
{
public:
	int* matrix = nullptr;
	size_t size = 0;

	MatrixAR(int* _matrix, size_t _size);
	MatrixAR() = default;
	~MatrixAR();

	MatrixAR* getTransposed() const;
	MatrixAR* multiply(const MatrixAR& b) const;
	MatrixAR* multiplyT(const MatrixAR& b) const;
	void multiply(const MatrixAR& b,int* result) const;
	void multiplyT(const MatrixAR& b, int* result) const;
};

class MatrixV // R^2 vector
{
public:
	std::vector<std::vector<int>*> *matrix;

	MatrixV() = default;
	MatrixV(std::vector<std::vector<int>*>* _matrix);
	~MatrixV();

	MatrixV* getTransposed() const;
	MatrixV* multiply(const MatrixV& b) const;
	MatrixV* multiplyT(const MatrixV& b) const;
	void multiply(const MatrixV& b, std::vector<std::vector<int>*>* result) const;
	void multiplyT(const MatrixV& b, std::vector<std::vector<int>*>* result) const;
};

class MatrixVR // R vector
{
public:
	std::vector <int> *matrix;
	size_t size = 0;
	MatrixVR(std::vector <int>* _matrix, size_t _size);
	MatrixVR() = default;
	~MatrixVR();

	MatrixVR* getTransposed() const;
	MatrixVR* multiply(const MatrixVR& b) const;
	MatrixVR* multiplyT(const MatrixVR& b) const;
	void multiply(const MatrixVR& b, std::vector<int>* result) const;
	void multiplyT(const MatrixVR& b, std::vector<int>* result) const;
};

int* getRawMatrix(const size_t size);
MatrixA* RtoA(const int* matrix, size_t size);
MatrixAR* RtoAR(const int* matrix, size_t size);
MatrixV* RtoV(const int* matrix, size_t size);
MatrixVR* RtoVR(const int* matrix, size_t size);

