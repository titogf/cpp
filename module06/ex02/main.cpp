#include "Base.hpp"

int main(){

    Base* b = generate();

    identify(b);
    identify(*b);
    
    return 0;
}