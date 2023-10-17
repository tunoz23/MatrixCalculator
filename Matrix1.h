#pragma once

#include <vector>
template<typename Type>
class Matrix
{
private: //Members
	size_t m, n;

public: //Members
	Type** m_Matrix;

public: //Member Functions
	Matrix(size_t rowCount, size_t columnCount);
	
	~Matrix();
	
	void printSize() const;
	void printMatrix() const;

	Matrix& operator^(const Matrix& other) const;

	Matrix& operator<<(std::vector<std::vector<Type>> array2D);

    Matrix& operator+(const Matrix& other) const;
};

