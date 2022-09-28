//
// Created by fodor.laszlo.carlos on 9/28/2022.
//

#include <cmath>
#include "util.h"
#include "Point.h"

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX() , 2 ) + pow( a.getY() - b.getY(),2) ) ;
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double ab , ac , ad  ;
    ab = distance( a , b ) ;
    ac = distance(a , c ) ;
    ad = distance( a , d ) ;
    if ( ac != 0 || ab != 0 || ad != 0 ) {
        if (
                (ab == ad && ac == ab * sqrt(2)) ||
                (ab == ac && ad == ab * sqrt(2)) ||
                (ac == ad && ab == ac * sqrt(2))
                ) {
            return true;
        }
    }
    return false ;
}

