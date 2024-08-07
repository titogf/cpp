#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy.getType()){}

Animal& Animal::operator=(const Animal& original){
    if (this != &original){
        _type = original.getType();
    }
    return (*this);
}

Animal::~Animal(){std::cout << "Animal destructor colled" << std::endl;}

std::string Animal::getType(void) const {return (_type);}

void    Animal::makeSound(void) const{
    std::cout << "Some generic Animal sound ..." << std::endl;
}