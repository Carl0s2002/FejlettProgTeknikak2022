#include <iostream>
#include <fstream>
#include <cmath>
#include "Point.h"
#include "util.h"
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
            ifstream fin("C:\\Users\\Admin\\Desktop\\Github\\FejlettProgTeknikak2022\\lab02\\Pontok.txt") ;
            if ( !fin ){
                cout << "File open error!" ;
            }
            while( !fin.eof() ){
                fin >> x >> y ;
                Point a(x , y ) ;
                fin >> x >> y ;
                Point b( x , y ) ;
                fin >> x >> y ;
                Point c( x , y ) ;
                fin >> x >> y ;
                Point d( x , y ) ;
                if ( isSquare( a , b , c , d ) ) {
                    cout << "Negyzet!" << endl ;
                }
                else{
                    cout << "Nem negyzet!" << endl ;
                }
            }
            fin.close();
            break;
        }
        case 7:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            points = createArray(n) ;
            cout << "A tomb elemei: " ;
            for ( int i = 0 ; i < n ; ++i ) {
                cout << points[i].getX() << " "  << points[i].getY() << endl;
            }
            deletePoints(points) ;
            break;
        }
        case 8:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            points = createArray(n) ;
            printArray( points , n ) ;
            deletePoints(points) ;
            break;
        }
        case 9:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            points = createArray(n) ;
            printArray( points , n ) ;
            pair<Point , Point> Closest_Points ;
            Closest_Points = closestPoints(points , n ) ;
            cout << "Legkozelebbi pontpar: " << Closest_Points.first.getX() << "-" << Closest_Points.first.getY()
            << " -> " << Closest_Points.second.getX() << "-" << Closest_Points.second.getY() ;
            deletePoints(points) ;
            break;
        }
        case 10:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            points = createArray(n) ;
            printArray( points , n ) ;
            pair<Point , Point> Farthest_Points ;
            Farthest_Points = farthestPoints(points , n ) ;
            cout << "Legtavolabbi pontpar: " << Farthest_Points.first.getX() << "-" << Farthest_Points.first.getY()
                 << " -> " << Farthest_Points.second.getX() << "-" << Farthest_Points.second.getY() ;
            deletePoints(points) ;
            break;
        }
        case 11:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            points = createArray(n) ;
            cout << "Rendezes elott:" << endl ;
            printArray( points , n ) ;
            sortPoints(points , n ) ;
            cout << "Rendezes utan:" << endl;
            printArray( points , n ) ;
            deletePoints(points) ;
            break;
        }
        case 12:{
            int n ;
            cout << "Valaszd ki a tomb elemeinek a szamat:" ;
            cin >> n ;
            Point* points = new Point[n] ;
            Point* Farthest_Points = new Point[10] ;
            points = createArray(n) ;
            printArray( points , n ) ;
            Farthest_Points = farthestPointsFromOrigin( points , n ) ;
            cout << "10 legtavolabbi pont az origotol:" << endl ;
            printArray(Farthest_Points , 10 ) ;
            deletePoints(points) ;
            deletePoints(Farthest_Points) ;
            break;
        }
        case 13:{
            cout << "Minden case-nel el lett vegezve a felszabaditas,ahol szukseges volt!" ;
            break;
        }
        default:{
            cout << "Ilyen feladat nem letezik!" ;
            break ;
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

