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
        out << what.coefficients[i] << "x^" << what.capacity - 1 - i << "+" ;
    }
    out << what.coefficients[what.capacity-1 ] ;
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
    delete [] that.coefficients ;
}

Polynomial Polynomial::derivative() const {
    Polynomial p = *this ;
    for ( int i = 0 ; i < this->capacity-1 ; ++i ) {
        p.coefficients[i] *= degree()-i ;
    }
    p.coefficients[this->capacity-1] = 0 ;
    return p ;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {

}


