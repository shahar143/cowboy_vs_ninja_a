//
// Created by super on 5/10/23.
//
#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;

Point::Point(double x, double y): x(x), y(y){}
Point::Point(): x(0), y(0){}

double Point::getX() const{
    return x;
}
double Point::getY() const{
    return y;
}

double Point::distance(const Point& other) const{
    return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
}

string Point::print() const{
    return "(" + to_string(x) + "," + to_string(y) + ")";
}

Point Point::moveTowards(const Point& src, const Point& dst, const int distance) const{
    double d = src.distance(dst);
    if(d <= distance){
        return dst;
    }
    double ratio = distance / d;
    double xs = src.getX() + (dst.getX() - src.getX()) * ratio;
    double ys = src.getY() + (dst.getY() - src.getY()) * ratio;
    return Point(xs, ys);
}
