#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
    _type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
    _type = copy.getType();
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original){
    if (this != &original){
        _type = original.getType();
    }
    std::cout << "WrongAnimal operator constructor called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor colled" << std::endl;}

std::string WrongAnimal::getType(void) const {return (_type);}

void    WrongAnimal::makeSound(void) const{
    std::cout << "Some generic WrongAnimal sound ..." << std::endl;
}