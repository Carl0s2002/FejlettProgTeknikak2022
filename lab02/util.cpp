//
// Created by fodor.laszlo.carlos on 9/28/2022.
//

#include "Point.h"
#include "util.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX() , 2 ) + pow( a.getY() - b.getY(),2) ) ;
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double ab , ac , ad  , atlo1 , atlo2 ;
    ab = distance( a , b ) ;
    ac = distance(a , c ) ;
    ad = distance( a , d ) ;
    atlo1 = ab * sqrt(2) ;
    atlo2 = ac * sqrt(2) ;
    if ( ac != 0 || ab != 0 || ad != 0 ) {
        if (
                (ab == ad && ac == atlo1) ||
                (ab == ac && ad == atlo1) ||
                (ac == ad && ab == atlo2)
                ) {
            return true;
        }
    }
    return false ;
}

Point* createArray(int numPoints) {
    srand(time(0)) ;
    Point* points = new Point[numPoints] ;
    for ( int i = 0 ; i < numPoints ; ++i ) {
         points[i] = Point( rand()%2000 , rand()%2000 ) ;
    }
    return points ;
}

void printArray(Point *points, int numPoints) {
    for ( int i = 0 ; i < numPoints ; ++i ) {
        cout << points[i].getX() << " " << points[i].getY() << endl ;
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    pair<Point, Point> Closest_Points;
    double minDistance = 2000 ;
    for ( int i = 0 ; i < numPoints ; ++i ) {
        for ( int j = 0 ; j < numPoints ; ++j ) {
            if ( i == j ){
                continue;
            }
            if (distance(points[i] , points[j]) < minDistance ){
                minDistance = distance(points[i] , points[j]) ;
                Closest_Points.first= points[i] ;
                Closest_Points.second = points[j] ;
            }
        }
    }
    return Closest_Points ;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    pair<Point,Point> Farthest_Points ;
    double maxDistance = 0 ;
    for ( int i = 0 ; i < numPoints ; ++i ) {
        for ( int j = 0 ; j < numPoints ; ++j ) {
            if ( i == j ){
                continue;
            }
            if (distance(points[i] , points[j]) > maxDistance ){
                maxDistance = distance(points[i] , points[j]) ;
                Farthest_Points.first= points[i] ;
                Farthest_Points.second = points[j] ;
            }
        }
    }
    return Farthest_Points ;
}
bool myFunction( Point i , Point j ){
    return (i.getX() < j.getX()) ;
}
void sortPoints(Point *points, int numPoints) {
    sort( points , points+numPoints ,  myFunction ) ;
}
bool arrange(Point i, Point j) {
    return (distance(i , Point(0,0) ) < distance(j , Point(0,0))) ;
}
Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    Point* farthestPoints = new Point[10] ;
    int elements = 0 ;
    for ( int i = 0 ; i < numPoints ; ++i ) {
        if ( elements != 9 ) {
            farthestPoints[elements] = points[i] ;
            elements++;
        }
        else{
            sort( farthestPoints , farthestPoints+10 , arrange ) ;
            if (!arrange( points[i] , farthestPoints[0])){
                farthestPoints[0] = points[i] ;
            }
        }
    }
    return farthestPoints ;
}

void deletePoints(Point *points) {
    delete [] points ;
}



