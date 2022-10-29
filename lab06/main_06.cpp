#include <iostream>
#include "Polynomial.h"
using namespace std ;
int main() {
    ///p1 kiiratasa
    double coef[]{ 1 , 2 , 1 } ;
    Polynomial p1( 2 , coef );
    cout << "p1:" << p1 << endl << endl  ;

    ///p1 fokszama
    cout << "Degree(p1):" << p1.degree() << endl << endl ;

    ///p1 eredmenye x-et ismerve
    int x ;
    cout << "Choose a value for x:" ;
    cin >> x;
    cout << "Result(p1): " << p1.evaluate(x) << endl << endl ;

    ///p1 derivaltja
    Polynomial p2 = p1.derivative() ;
    cout << "Derivative(p1):";
    cout << p2 << endl << endl ;

    ///Copy konstruktor
    cout << "Copy constructor:" << endl;
    Polynomial p3 = p1 ;
    cout << "p3 = p1 = " << p3 << endl << endl ;

    ///Move konstruktor
    cout << "Move constructor:" << endl;
    Polynomial p4 = move(p2) ;
    cout << "Moved from p2 to p4; p4 = " << p4 << endl << endl;

    ///Index operator
    cout << "Index operator:" << endl ;
    for ( int i = 0 ; i < p1.degree()+1 ; ++i ) {
        cout << "p1[" << i << "]= " << p1[i] << endl  << endl ;
    }

    /// "-" Operator(tagadas)
    cout << "'-' Operator: " << endl ;
    cout << "-p1 = " << -p1 << endl << endl ;

    /// "+" Operator
    cout << "'+' Operator: " << endl ;
    cout << "p1 + p4 = " << p1+p4 << endl << endl ;

    /// "-" Operator
    cout << "'-' Operator:" << endl ;
    cout << "p1 - p4 = " << p1 - p4 << endl << endl ;

    /// "*" Operator
    cout << "'*' Operator:" << endl ;
    cout << "p1 * p4 = " << p1 * p4 ;
    return 0;
}