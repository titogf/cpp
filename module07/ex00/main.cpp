#include "whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

    std::cout << "--- Swapping a and b ---" << std::endl;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout << std::endl;

    std::string c = "Lucas";
    std::string d = "Alberto";

    std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

    std::cout << "--- Swapping c and d ---" << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}