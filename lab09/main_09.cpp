#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
using namespace std;
int main() {
    Szemely szemely( "Fodor" , "Carlos" , 2002 );
    cout << szemely ;
    cout << endl << endl ;
    Alkalmazott alkalmazott( "Fodor" , "Carlos" , 2002 , "Programozo" );
    cout << alkalmazott ;
    cout << endl << endl ;
    Alkalmazott alkalmazott1( "Fodor1" , "Carlos1" , 2002 , "Programozo" );
    Alkalmazott alkalmazott2( "Fodor2" , "Carlos2" , 2002 , "Programozo" );
    Manager manager( "Fod" , "Car" , 2002 , "manager" ) ;
    manager.addAlkalmazott( &alkalmazott ) ;
    manager.addAlkalmazott( &alkalmazott1 ) ;
    manager.addAlkalmazott( &alkalmazott2 ) ;
    cout << manager ;
    cout << endl << endl ;
    manager.deleteAlkalmazott(&alkalmazott) ;
    cout << "Torles utan" << endl ;
    cout << manager ;
    return 0;
}