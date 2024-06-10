#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point d(14, 15);
    Point e(100, 15);

    if (bsp(a, b, c, d))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Outside triangle" << std::endl;
    if (bsp(a, b, c, e))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Outside triangle" << std::endl;
    return (0);
}