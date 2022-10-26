//
// Created by fodor.laszlo.carlos on 10/12/2022.
//

#include "Point.h"
int Point::counter{0};
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
    this->counter++ ;
}
Point::Point(const Point &point) {
    this->x = point.getX() ;
    this->y = point.getY() ;
    counter++ ;
}
//Point::Point(Point &&point) {
//    this->x = point.getX() ;
//    this->y = point.getY() ;
//    point.x = 0 ;
//    point.y = 0 ;
//}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(point.getX() - this->getX() , 2 ) + pow( point.getY() - this->getY(),2) ) ;
}
