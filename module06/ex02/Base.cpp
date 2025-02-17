#include "Base.hpp"

Base* generate(void){
    
    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomNumber = (std::rand() % 3) + 1;

    if (randomNumber == 1){
        std::cout << "New A class" << std::endl;
        return new A;
    }
    else if (randomNumber == 2){
        std::cout << "New B class" << std::endl;
        return new B;
    }
    else{
        std::cout << "New C class" << std::endl;
        return new C;
    }
    return NULL;
}

void identify(Base *p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    if (a)
        std::cout << "*-> A" << std::endl;
    else if (b)
        std::cout << "*-> B" << std::endl;
    else if (c)
        std::cout << "*-> C" << std::endl;
}

void identify(Base& p){
    try {
        A &a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "&-> A" << std::endl;
    } catch (std::exception &e) {
        std::cout << "A not found" << std::endl;
    }

    try {
        B &b = dynamic_cast<B &>(p);
        (void) b;
        std::cout << "&-> B" << std::endl;
    } catch (std::exception &e) {
        std::cout << "B not found" << std::endl;
    }

    try {
        C &c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "&-> C" << std::endl;
    } catch (std::exception &e) {
        std::cout << "C not found" << std::endl;
    }
}