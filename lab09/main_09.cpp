#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"
using namespace std;
int main() {
//    Szemely szemely( "Fodor" , "Carlos" , 2002 );
//    cout << szemely ;
//    cout << endl << endl ;
//    Alkalmazott alkalmazott( "Fodor" , "Carlos" , 2002 , "Programozo" );
//    cout << alkalmazott ;
//    cout << endl << endl ;
//    Alkalmazott alkalmazott1( "Fodor1" , "Carlos1" , 2002 , "Programozo" );
//    Alkalmazott alkalmazott2( "Fodor2" , "Carlos2" , 2002 , "Programozo" );
//    Manager manager( "Fod" , "Car" , 2002 , "manager" ) ;
//    manager.addAlkalmazott( &alkalmazott ) ;
//    manager.addAlkalmazott( &alkalmazott1 ) ;
//    manager.addAlkalmazott( &alkalmazott2 ) ;
//    cout << manager ;
//    cout << endl << endl ;
//    manager.deleteAlkalmazott(&alkalmazott) ;
//    cout << "Torles utan" << endl ;
//    cout << manager ;
    cout << endl << endl << "\t" << "Ceges feladat:" << endl << endl ;
    Ceg ceg("Kaufland") ;
    vector<Alkalmazott> alkalmazottak;
    vector<Manager> managerek ;
    managerek.reserve(3) ;
    alkalmazottak.reserve(10) ;
    for ( int i = 0 ; i < 7 ; ++i ) {
        alkalmazottak.emplace_back(Alkalmazott("Fodor" , "Carlos" , 1990+i , "Programozo")) ;
    }
    for ( int i = 0 ; i < 3 ; ++i ) {
        managerek.emplace_back(Manager("Fodor" , "Carlos" , 1980+i , "")) ;
    }
    for( auto& a:alkalmazottak){
        ceg.hire(a);
    }
    for ( auto& m: managerek ){
        ceg.promote(m) ;
    }
    ceg.printAlkalmazottak();
    for ( auto& a : alkalmazottak ) {
        managerek[0].addAlkalmazott(&a);
    }
    ceg.printManagerek() ;
    return 0;
}