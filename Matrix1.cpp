#include "Matrix1.h"
#include <iostream>
#include <vector>
template<typename Type>
Matrix<Type>::Matrix(size_t rowCount, size_t columnCount)
	:m(rowCount), n(columnCount), m_Matrix(new Type* [m])
{
	
	for (int i = 0; i < m; i++)
		m_Matrix[i] = new Type[n];
	
}

template<typename Type>
Matrix<Type>::~Matrix()
{
	for (int i = 0; i < m; i++)
		delete[] m_Matrix[i];
	delete[] m_Matrix;
	
}

template<typename Type>
void Matrix<Type>::printSize() const 
{
	std::cout << "m: " << this->m << " n: " << this->n << std::endl;
}

template<typename Type>
Matrix<Type>& Matrix<Type>::operator^(const Matrix<Type>& other) const
{	
	
	Type sum;
	if (this->n != other.m)
	{
		std::cout << "These matrices cannot be multiplied" << std::endl;
		return { *(new Matrix<Type>(0,0)) };
	}

	Matrix* resultMatrix = new Matrix(this->m, other.n); // mXn

	for (int i = 0; i < resultMatrix->m; i++) {

		for (int j = 0; j < resultMatrix->n; j++) {
			sum = 0;

			for (int k = 0; k < this->n; k++) 
				sum += this->m_Matrix[i][k] * other.m_Matrix[k][j];

			
			resultMatrix->m_Matrix[i][j] = sum;
		}
	}
	return *resultMatrix;
}

template<typename Type>
void Matrix<Type>::printMatrix() const
{
	for (int i = 0; i < this->m; i++)
	{
		
			for (int j = 0; j < this->n; j++)
			
				std::cout << this->m_Matrix[i][j];
			
		std::cout << "\n";
	}

}
template<typename Type>
Matrix<Type>& Matrix<Type>::operator+(const Matrix& other) const
{
    auto& resultMatrix = *(new Matrix<Type>(this->m,this->n));

    const Matrix &ref = *this;
    if ((m != other.m) || (n != other.n)) {
#ifdef TEXTFEEDBACK
        std::cout << "Bu ikili toplanamaz!" << std::endl;
#endif
        return resultMatrix;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            resultMatrix.m_Matrix[i][j] = ref.m_Matrix[i][j] + other.m_Matrix[i][j];
    return resultMatrix;
}

template<> void Matrix<double>::printMatrix() const
{
	for (int i = 0; i < this->m; i++)
	{

		for (int j = 0; j < this->n; j++)
			printf("%9.2lf", this->m_Matrix[i][j]);
		std::cout << '\n';
	}

}

template<> void Matrix<int>::printMatrix() const
{
	for (int i = 0; i < this->m; i++)
	{

		for (int j = 0; j < this->n; j++)
			printf("%6d", this->m_Matrix[i][j]);
		std::cout << '\n';
	}

}
template<typename Type>
Matrix<Type>& Matrix<Type>::operator<<(const std::vector<std::vector<Type>> array2D)
{
	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
			this->m_Matrix[i][j] = array2D[i][j];
	}
	return *this;
}

int main()
{
	Matrix<double> Matrix1(1,3);

    std::vector<std::vector<double>> dizi2d = {
            {1,2,3},
           
            };

    Matrix1 << dizi2d;
    std::cout << "Seyma Matrix\n";
    Matrix1.printMatrix();

    Matrix<double> Matrix2(3,1);
    std::vector<std::vector<double>> dizi2d_2 = {
            {1},
            {3},
            {4}};
    Matrix2 << dizi2d_2;
    std::cout << "Zehra Matrix\n";
    Matrix2.printMatrix();

    std::cout << "sonuc Matrix\n";
	(Matrix2 ^ Matrix1).printMatrix();


}