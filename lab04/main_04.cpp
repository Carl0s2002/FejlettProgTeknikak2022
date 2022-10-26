#include <iostream>
#include <vector>
#include <algorithm>
#include "PointSet.h"
#include <iomanip>
#include "Point.h"
using namespace std;
int main() {
//    vector<int> v1 ;
//    v1.reserve(1025) ;
//    cout << "Size:" << v1.size()  << endl;
//    cout << "Capacity:" << v1.capacity() << endl ;
//    for ( int i = 0 ; i < 1025 ; ++i ){
//        v1.emplace_back( i ) ;
////      v1[i] = i ;  !!! size = 0 marad
//        cout << "Size:" << v1.size()  << " " << "Capacity:" << v1.capacity() << endl ;
//    }
//    int x1[] { 1 , 2 , 3 , 4 , 5 , 6 , 7 };
//    vector<int> x2{1 , 2 , 3 , 4 , 5 , 6 , 7 };
//    cout << *min_element( x1  , x1 + 7 ) << endl ;
//    cout << *min_element(x2.begin() , x2.end()) << endl ;

//    int n = 2;
//    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
//    cout<< fixed;
//    for( int i= 0; i<12; ++i ){
//        PointSet pSet( n );
//        cout<<setw(6)<<n<<" ";
//        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
//        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
//        cout<<setw(10) << pSet.numDistances()<<" ";
//        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
//        cout << endl;
//        n = n << 1;
//    }
//
//    cout << endl ;
//    PointSet pointSet( 10 ) ;
//    cout << "Pontok rendezese Y koordinatak szerint:" << endl ;
//    pointSet.sortPointsY() ;
//    pointSet.printPoints() ;
//    cout << endl << "Pontok rendezese X koordinatak szerint:" << endl ;
//    pointSet.sortPointsX() ;
//    pointSet.printPoints() ;
//    cout << endl << "Tavolsagok elrendezve:" << endl ;
//    pointSet.sortDistances() ;
//    pointSet.printDistances() ;


//    PointSet pset1(10);
//    cout<<"#points: " <<Point::getCounter()<<endl;
//    PointSet pset2(20);
//    cout<<"#points: " <<Point::getCounter()<<endl;

    Point p1( 1 , 2 ) , p2 ;
    cout << Point::getCounter() << endl;
    Point p3 = p1 ;
    Point p4(p2) ;
    cout << Point::getCounter() << endl;
    Point *p5 = new Point(3,3) ;
    cout << Point::getCounter() << endl;
    delete p5  ;
    cout << Point::getCounter() << endl;
    return 0;
}