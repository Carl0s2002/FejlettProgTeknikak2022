//
// Created by fodor.laszlo.carlos on 10/26/2022.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree+1 ;
    this->coefficients = new double[capacity] ;
    for ( int i = 0 ; i < this->capacity ; ++i ) {
        this->coefficients[i] = coefficients[i] ;
    }
}

ostream &operator<<(ostream &out, const Polynomial &what) {
    for ( int i = 0 ; i < what.capacity-1 ; ++i ){
        out << "(" << what.coefficients[i] << "x^" << what.capacity - 1 - i << ")"  << "+" ;
    }
    out << "(" << what.coefficients[what.capacity-1 ] << ")" ;
    return out ;
}

int Polynomial::degree() const {
    return this->capacity-1;
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity ;
    this->coefficients = new double [this->capacity] ;
    for ( int i = 0 ; i < this->capacity ; ++i ) {
        this->coefficients[i] = that.coefficients[i];
    }
}

double Polynomial::evaluate(double x) const {
    double p = this->coefficients[0] ;
    for ( int i = 1 ; i < this->capacity ; ++i ) {
        p = p*x + this->coefficients[i] ;
    }
    return p ;
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity ;
    this->coefficients = that.coefficients ;
    that.capacity = 0 ;
    that.coefficients = nullptr ;
}

Polynomial Polynomial::derivative() const {
    Polynomial p = *this ;
    for ( int i = 0 ; i < this->capacity-1 ; ++i ) {
        p.coefficients[i] *= degree()-i ;
    }
    p.coefficients[this->capacity-1] = 0 ;
    p.capacity-- ;
    return p ;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    for ( int i = 0 ; i < a.capacity ; ++i ) {
        a.coefficients[i] *= -1 ;
    }
    return a ;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if ( a.capacity > b.capacity ) {
        Polynomial addition( a.degree() , a.coefficients ) ;
        for ( int i = a.degree() - b.degree() ; i < a.capacity ; ++i ) {
             addition.coefficients[i] += b.coefficients[i-(a.degree()-b.degree())] ;
        }
        return addition ;
    }
        Polynomial addition( b.degree() , b.coefficients ) ;
        for ( int i = b.degree() - a.degree() ; i < b.capacity ; ++i ) {
            addition.coefficients[i] += a.coefficients[i-(b.degree()-a.degree())] ;
        }
    return addition ;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    if ( a.capacity > b.capacity ) {
        Polynomial substract(a.degree() , a.coefficients ) ;
        for ( int i = a.degree() - b.degree() ; i < a.capacity ; ++i ) {
            substract.coefficients[i] -= b.coefficients[i-(a.degree()-b.degree())] ;
        }
        return substract ;
    }
    Polynomial substract(b.degree() , b.coefficients ) ;
    for ( int i = b.degree() - a.degree() ; i < b.capacity ; ++i ) {
        substract.coefficients[i] -= a.coefficients[i-(b.degree()-a.degree())] ;
    }
    return substract ;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    double helper[a.degree()+b.degree()+1] ;
    Polynomial multiplication( a.degree()+b.degree() , helper ) ;
    for ( int i = 0 ; i < multiplication.capacity ; ++i ) {
        multiplication.coefficients[i] = 0 ;
    }
    for ( int i = 0 ; i < a.capacity ; ++i ) {
        for ( int j = 0 ; j < b.capacity ; ++j ) {
            multiplication.coefficients[i+j] += a.coefficients[i] * b.coefficients[j] ;
        }
    }
    return multiplication ;
}


