#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(const Point& copy): _x(copy.getX()), _y(copy.getY()){}

Point& Point::operator=(const Point& original)
{
    if (this != &original)
    {
        (Fixed)this->_x = original.getX();
        (Fixed)this->_y = original.getY();
    }
    return (*this);  
}

Point::~Point(){}

Fixed Point::getX() const
{
    return (_x);
}
Fixed Point::getY() const
{
    return (_y);
}