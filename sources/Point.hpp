//
// Created by super on 5/10/23.
//

#ifndef COWBOY_VS_NINJA_A1_POINT_HPP
#define COWBOY_VS_NINJA_A1_POINT_HPP

#include <iostream>
using namespace std;

namespace ariel{
    class Point{
    private:
        int x;
        int y;
    public:
        Point(double x, double y);
        Point();

        double getX() const;
        double getY() const;

        double distance(const Point& other) const;
        string print() const;
        Point moveTowards(const Point& src, const Point& dst, const int distance) const;
    };
}

#endif //COWBOY_VS_NINJA_A1_POINT_HPP
