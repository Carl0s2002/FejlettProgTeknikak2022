//
// Created by fodor.laszlo.carlos on 9/28/2022.
//

#ifndef MAIN_01_CPP_UTIL_H
#define MAIN_01_CPP_UTIL_H

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Point.h"
using namespace std ;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
Point* createArray(int numPoints ) ;
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
bool myFunction( Point i , Point j ) ;
void sortPoints(Point* points, int numPoints);
bool arrange( Point i , Point j ) ;
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);
#endif //MAIN_01_CPP_UTIL_H
