//
// Created by fodor.laszlo.carlos on 9/28/2022.
//

#ifndef MAIN_01_CPP_POINT_H
#define MAIN_01_CPP_POINT_H
#include <iostream>
class Point {
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};


#endif //MAIN_01_CPP_POINT_H
