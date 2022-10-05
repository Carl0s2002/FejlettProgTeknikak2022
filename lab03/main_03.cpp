#include <iostream>
#include "List.h"

using namespace std;
int main() {
    cout << "Lista deklaralasa,beszurasa es kiiratasa:" << endl ;
    List list1 ;
    for ( int i = 0 ; i < 10 ; ++i ) {
        list1.insertFirst(i) ;
        list1.print() ;
    }
    cout << endl << "Valassz egy erteket:" ;
    int d ;
    cin >> d ;
    if (list1.exists(d)) {
        cout << "A kivalasztott ertek szerepel a listaban!" << endl << endl ;
    }
    else{
        cout << "A kivalasztott ertek nem szerepel a listaban!" << endl << endl ;
    }
    cout << "A lista merete:" << list1.size() << endl << endl;
    if ( list1.empty() ){
        cout << "A lista ures!" << endl << endl ;
    }
    else {
        cout << "A lista nem ures!" << endl << endl ;
    }
    cout << "Elso elem torlese:" << endl ;
    cout << "Az elso elem amely ki lett torolve a(z)" << list1.removeFirst() << "-es/as ertek!" << endl << endl;
    cout<< "Valassz egy elemet:" ;
    cin >> d ;
    int helper ;
    cout << " Milyen elemet toroljon ki?" << endl << "Kissebb(0)" << endl << "Egyenlo(1)" << endl << "Nagyobb(2)"  << endl ;
    cin >> helper ;
    return 0;
}
