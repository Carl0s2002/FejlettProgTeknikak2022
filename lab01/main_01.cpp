#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std ;

void test_function1() ;
void test_function2();
void test_function3();
void test_function4();
void test_function5() ;
void test_function6() ;
int main(){
    cout << "Melyik feladattipus legyen?" << endl << "1.Fugvenyek(ismetles)" << endl << "2.Karakterlancok" << endl ;
    unsigned int feladatTipus ;
    cin >> feladatTipus ;
    switch (feladatTipus) {
        case 1: {
            cout << "Valassz egy feladatot!" << endl;
            unsigned int feladat;
            cin >> feladat;
            switch (feladat) {
                case 1: {
                    test_function1();
                    break;
                }
                case 2: {
                    test_function2();
                    break;
                }
                case 3: {
                    test_function3();
                    break;
                }
                case 4: {
                    test_function4();
                    break;
                }
                case 5: {
                    test_function5();
                    break;
                }
                default: {
                    cout << "Ilyen feladat nem letezik!";
                    break;
                }
            }
            break;
        }
        case 2:{
            cout << "Valassz egy feladatot!" << endl;
            unsigned int feladat;
            cin >> feladat;
            switch (feladat) {
                case 1:{
                    test_function6() ;
                    break;
                }
                case 2:{
                    string text = "Harom Szapis egyetem letezik Romaniaban";
                    cout << "A szavak szama:" << countWords(text) ;
                    break;
                }
                case 3:{
                    string text = "Harom Szapis egyetem letezik Romaniaban";
                    text = code(text) ;
                    cout << text ;
                    break;
                }
                default:{
                    cout << "Ilyen feladat nem letezik!" ;
                    break;
                }
            }
            break;
        }
        default:{
            cout << "Ilyen feladattipus nem letezik!" ;
            break;
        }
    }
    return 0 ;
}

void test_function1(){
    for ( int i = 0 ; i < 128 ; ++i ) {
        cout << i << ":" << countBits(i) << endl ;
    }
}
void test_function2(){
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }
        else{
            cout<<"Impossible operation!" << endl;
        }
    }
}
void test_function3(){
    int numOfElements ;
    cout << "Ird le a tomb hosszat!" ;
    cin >> numOfElements ;
    double array[numOfElements] ;
    if ( numOfElements != 0 ) {
        cout << "Ird le a tomb elemeit:" << endl;
        for (int i = 0; i < numOfElements; ++i) {
            cout << i + 1 << ". " << endl;
            cin >> array[i];
        }
    }
    cout << "A tomb elemeinek az atlaga:" << mean( array , numOfElements ) ;
}

void test_function4() {
    int numOfElements ;
    cout << "Ird le a tomb hosszat!" ;
    cin >> numOfElements ;
    double array[numOfElements] ;
    if ( numOfElements != 0 ) {
        cout << "Ird le a tomb elemeit:" << endl;
        for (int i = 0; i < numOfElements; ++i) {
            cout << i + 1 << ". " << endl;
            cin >> array[i];
        }
    }
    cout << "A tomb elemeinek a szorasa:" << szoras(array , numOfElements);
}

void test_function5() {
    int numOfElements ;
    cout << "Ird le a tomb hosszat!" ;
    cin >> numOfElements ;
    double array[numOfElements] ;
    if ( numOfElements != 0 ) {
        cout << "Ird le a tomb elemeit:" << endl;
        for (int i = 0; i < numOfElements; ++i) {
            cout << i + 1 << ". " << endl;
            cin >> array[i];
        }
    }
    pair<double,double> biggestValues ;
    biggestValues = twoBiggest(array , numOfElements) ;
    cout << "A tomb elemeinek a ket legnagyobb szama:" << biggestValues.first << " " << biggestValues.second  ;
}

void test_function6() {
    stringToNumeric();
}
