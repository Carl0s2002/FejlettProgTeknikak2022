//
// Created by fodor.laszlo.carlos on 10/12/2022.
//

#ifndef MAIN_04_CPP_POINT_H
#define MAIN_04_CPP_POINT_H
#include <cmath>
#define M 2000


class Point{
private:
    int x, y;
    static int counter ;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
    Point (const Point& point) ;
    ~Point() {
        counter-- ;
    }
    static int getCounter(){
        return counter ;
    }
//    Point( Point &&point) ;
};



#endif //MAIN_04_CPP_POINT_H
