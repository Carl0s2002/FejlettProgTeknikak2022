//
// Created by fodor.laszlo.carlos on 10/19/2022.
//

#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mCols = mCols ;
    this->mRows = mRows ;
    mElements = new double* [this->mRows] ;
    for ( int i = 0 ; i < this->mCols ; ++i  ) {
        this->mElements[i] = new double[this->mCols] ;
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows ;
    this->mCols = what.mCols ;
    this->mElements = what.mElements ;
}

Matrix::Matrix(Matrix &&what) {
    this->mCols = what.mCols ;
    this->mRows = what.mRows ;
    this->mElements = what.mElements ;
    what.mCols = 0 ;
    what.mRows = 0 ;
    what.mElements = nullptr ;
}

void Matrix::fillMatrix(double value) {
    for ( int i = 0 ; i < this->mRows ; ++i ) {
        for ( int j = 0 ; j < this->mCols ; ++j ) {
            this->mElements[i][j] = value ;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for ( int i = 0 ; i < this->mRows ; ++i ) {
        for (int j = 0; j < this->mCols; ++j) {
            os << this->mElements[i][j] << " ";
        }
        os << endl ;
    }
}

Matrix::~Matrix() {
    for ( int i = 0 ; i < this->mRows ; ++i  ) {
            delete[] this->mElements[i];
        }
    this->mElements = nullptr ;
    this->mCols = 0 ;
    this->mRows = 0 ;
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd ;
    mt19937 gen(rd()) ;
    uniform_real_distribution<> distribution(a , b );
    for ( int i = 0 ; i < this->mRows ; ++i  ){
        for ( int j = 0 ; j < this->mCols ; ++j){
            this->mElements[i][j] = distribution(gen) ;
        }
    }
}

bool Matrix::isSquare() const {
    return this->mCols == this->mRows ;
}


Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix temp(x.mRows , x.mCols) ;
    if ( x.mRows == y.mRows || x.mCols == y.mCols ) {
        for ( int i = 0 ; i < x.mRows ; ++i ) {
            for ( int z = 0 ; z < x.mCols ; ++z ) {
                double helper = 0 ;
                for (int j = 0; j < x.mCols; ++j) {
                    helper += x.mElements[i][j] * y.mElements[j][i];
                }
                temp.mElements[i][z] = helper ;
            }
        }
        return temp ;
    }
    throw out_of_range("Out of range!") ;
}

istream &operator>>(istream &is, Matrix &mat) {
    for ( int i = 0 ; i < mat.mRows ; ++i ) {
        for ( int j = 0 ; j < mat.mCols ; ++j ) {
            is >> mat.mElements[i][j] ;
        }
    }
    return is ;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for ( int i = 0 ; i < mat.mRows ; ++i ) {
        for ( int j = 0 ; j < mat.mCols ; ++j ) {
            os << mat.mElements[i][j] << " " ;
        }
        os << endl ;
    }
    return os ;
}

double *Matrix::operator[](int index) {
    return this->mElements[index] ;
}

double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    for ( int i = 0 ; i <  mat.mRows ; ++i ) {
        for ( int  j = 0 ; j < mat.mCols ; ++j ) {
            this->mElements[i][j] = mat.mElements[i][j] ;
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    this->mCols = mat.mCols ;
    this->mRows = mat.mRows ;
    mat.mCols = 0;
    mat.mRows = 0 ;
    for ( int i = 0 ; i <  mat.mRows ; ++i ) {
        for ( int  j = 0 ; j < mat.mCols ; ++j ) {
            this->mElements[i][j] = mat.mElements[i][j] ;
        }
    }
    mat.mElements = nullptr ;
    return *this;
}

Matrix operator+( const Matrix &x , const Matrix &y) {
    if ( x.mRows == y.mRows && y.mCols == x.mCols ) {
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

