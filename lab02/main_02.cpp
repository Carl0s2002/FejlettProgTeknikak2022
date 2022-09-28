#include <iostream>
#include "Point.h"
#include "util.h"
#include <fstream>
using namespace std;
void test_distance();
void test_square();
int main(int argc, char** argv) {
    unsigned int feladat ;
    cout << "Hanyas feladat legyen?" << endl ;
    cin >> feladat ;
    switch (feladat) {
        case 4 :{
            test_distance() ;
            break;
        }
        case 5:{
            test_square() ;
            break;
        }
        case 6:{
            int x , y ;
            ifstream ifs("points.txt" ) ;
            if ( !ifs ) {
                cout << "File open error!" << endl ;
                return 1 ;
            }
            while( !ifs.eof() ){
                ifs>>x >> y ;
                Point a(x , y ) ;
                ifs >> x >> y ;
                Point b( x , y ) ;
                ifs >> x >> y ;
                Point c( x , y ) ;
                ifs >> x >> y ;
                Point d( x , y ) ;
                if ( isSquare( a , b , c , d ) ) {
                    cout << "Negyzet!" << endl ;
                }
                else{
                    cout << "Nem negyzet!" << endl ;
                }
            }
            ifs.close();
            break;
        }
    }
    return 0;
}
void test_distance() {
    Point p1(0 , 1 ) ;
    cout << "distance(p1 , p1):" << distance(p1 , p1) << endl ;
    cout << "distance(p1 , Point(3 , 4):" << distance(p1 , Point(3 ,4)) << endl ;
}

void test_square() {
    Point p1( 0 , 0 );
    Point p2( 1  ,  0 ) ;
    Point p3( 1 , 1 ) ;
    Point p4( 0 , 1 ) ;
    cout << "Negyzet:" << isSquare( p1 , p2 , p3 , p4 ) ;
}

