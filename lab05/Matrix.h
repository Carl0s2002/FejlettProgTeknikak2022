//
// Created by fodor.laszlo.carlos on 10/19/2022.
//

#ifndef MAIN_05_CPP_MATRIX_H
#define MAIN_05_CPP_MATRIX_H
#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
public:
//Methods
// Default constructor
    Matrix( int mRows = 10, int mCols =10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix( Matrix&& what );
// Destructor
    ~Matrix();
    //fills the matrix with identical elements
    void fillMatrix(double value);
//fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
//prints the matrix
    void printMatrix(ostream& os = cout) const;
    //checks whether this matrix is a square one
    bool isSquare() const;
    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}
    // operation is permitted on matrices having the same dimensions
// otherwise throws an out_of_range exception!!
    friend Matrix operator+(const Matrix& x, const Matrix& y);
// operation is permitted on matrices having proper dimensions
// otherwise throws an out_of_range exception!!
    friend Matrix operator*(const Matrix& x, const Matrix& y);
private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};
Matrix operator+(const Matrix &x, const Matrix &y) {
    if ( x.mRows == y.mCols && y.mRows == y.mCols ) {
        Matrix temp( x.mRows , x.mCols ) ;
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                temp.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return temp ;
    }
        throw out_of_range("Out of range!") ;
}

#endif //MAIN_05_CPP_MATRIX_H
