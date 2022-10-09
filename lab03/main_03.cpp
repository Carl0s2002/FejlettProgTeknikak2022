#include <iostream>
#include "List.h"
#include "Stack.h"

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
    cout << " Milyen elemet toroljon ki?" << endl << "Kissebb(0)" << endl << "Egyenlo(1)" << endl << "Nagyobb(2)"  << endl ;
    int help ;
    List::DeleteFlag helper ;
    cin >> help;
    switch (help) {
        case 0 :{
            helper = List::DeleteFlag::LESS ;
            break;
        }
        case 1:{
            helper = List::DeleteFlag::EQUAL ;
            break;
        }
        case 2:{
            helper = List::DeleteFlag::GREATER ;
            break;
        }
    }
    list1.remove(d , helper ) ;
    list1.print();
    help = list1.size() ;
    Stack stack1(help) ;
    cout << endl << "A verem ertekei a listabol:" << endl ;
    for ( int i = 0 ; i < list1.size() ; ++i ) {
        if ( i < list1.size() || i > -1 ){
            help = list1.number(i);
            stack1.push(help) ;
        }
    }
    stack1.print();
    cout << "A pop muvelet elvegzese utan:" << endl ;
    stack1.pop() ;
    stack1.print() ;
    return 0;
}
