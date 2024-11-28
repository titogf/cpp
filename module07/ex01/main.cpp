#include "iter.hpp"

template<typename T>
void print(T c){
    std::cout << c;
}

int main( void ) {
    int i[] = {1,2,3,4,5};
    char str[6] = "hello";

    ::iter(i, 5, print);
    std::cout << std::endl;
    ::iter(str, 5, print);
    std::cout << std::endl;

    return 0;
}