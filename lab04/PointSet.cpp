//
// Created by fodor.laszlo.carlos on 10/12/2022.
//

#include "PointSet.h"

bool bool2D[M+1][M+1] {false};

void reset(){
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            bool2D[ i ][ j ] = false;
        }
    }
}


PointSet::PointSet(int n) {
    reset();

//
    this->points.reserve(n) ;
    this->distances.reserve((n*(n-1))/2) ;
    random_device rd ;
    mt19937 gen(rd()) ;
    uniform_int_distribution<> distribution(0 , M );
    this->n = n ;

    for (  ; this->points.size() < n ;  ) {
        int seged1 = distribution(gen) , seged2 = distribution(gen) ;
        if (!bool2D[seged1][seged2]){
            bool2D[seged1][seged2] = true ;
            this->points.emplace_back(Point(seged1 , seged2) ) ;
        }
    }

    computeDistances() ;
}

void PointSet::computeDistances() {
    for ( int i = 0 ; i < this->points.size() ; ++i ){
        for ( int j = i + 1 ; j < this->points.size() ; ++j ) {
            this->distances.emplace_back(this->points[i].distanceTo(this->points[j])) ;
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(this->distances.begin() , this->distances.end()) ;
}

double PointSet::minDistance() const {
    return *min_element(this->distances.begin() , this->distances.end());
}

int PointSet::numDistances() const {
    return this->distances.size();
}

void PointSet::printPoints() const {
    cout << "Az osszes pontok:" << endl;
    for ( Point point : this->points ){
        cout << point.getX() << " ";
        cout << point.getY() << " ";
        cout << endl ;
    }
}

void PointSet::printDistances() const {
        for ( int i = 0 ; i < this->distances.size() ; ++i ){
            cout << i << "st/nd/rd/th distance:" <<  this->distances[i] << endl ;
        }
}

int PointSet::numDistinctDistances() {
//    bool ok = true ;
//    vector<double> distinctDistance ;
//    distinctDistance.reserve((this->n*(this->n-1))/2) ;
//    for ( double distance: this->distances ) {
//        for ( double distinct : distinctDistance ) {
//            if ( distinct == distance ) {
//                ok = false ;
//            }
//        }
//        if (ok) {
//            distinctDistance.emplace_back(distance) ;
//        }
//        ok = true ;
//    }
//    return distinctDistance.size() ;
    return unique(this->distances.begin() ,this->distances.end()) - this->distances.begin() ;
}
bool sortingX( Point p1  , Point p2 ) {
    return ( p1.getX() < p2.getX() ) ;
}
void PointSet::sortPointsX() {
    sort( this->points.begin() , this->points.end() , sortingX ) ;
}
bool sortingY( Point p1 , Point p2 ) {
    return ( p1.getY() < p2.getY() ) ;
}
void PointSet::sortPointsY() {
    sort( this->points.begin() , this->points.end() , sortingY) ;
}

void PointSet::sortDistances() {
    sort( this->distances.begin() , this->distances.end() );
}
