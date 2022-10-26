#include <iostream>
#include "Polynomial.h"
using namespace std ;
int main() {
    double coef[]{ 1 , 2 , 1 } ;
    Polynomial p1( 2 , coef );
    cout << "p1:" << p1 << endl ;
    cout << "Degree(p1):" << p1.degree() << endl ;
    cout << "Result(p1) if x = 2: " << p1.evaluate(2) ;
    return 0;
}