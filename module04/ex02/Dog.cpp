#include "Dog.hpp"

Dog::Dog() : _brain(new Brain){
    std::cout << "Dog constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy){
    _brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& original){
    if (this != &original){
        Animal::operator=(original);
        delete this->_brain;
        _brain = new Brain(*original._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

const Brain& Dog::getBrain() const{ return *_brain;}

void Dog::makeSound() const {
    std::cout << "Guau guau guau ..." << std::endl;
}