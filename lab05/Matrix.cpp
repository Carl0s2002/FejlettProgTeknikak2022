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
    delete[] this->mElements ;
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
    if ( x.mRows == y.mRows || x.mRows == y.mCols ) {
        Matrix temp(x.mRows , x.mCols) ;
    }
        throw out_of_range("Out of range!") ;
}
