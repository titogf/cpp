#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{

    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &copy);
        Point& operator=(const Point& original);
        ~Point(void);
        Fixed getY() const;
        Fixed getX() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif