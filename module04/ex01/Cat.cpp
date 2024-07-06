#include "Cat.hpp"

Cat::Cat() : _brain(new Brain){
    std::cout << "Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy){
    _brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat& original){
    if (this != &original) {
        Animal::operator=(original);  // Asigna la parte de `Animal`
        delete this->_brain;
        this->_brain = new Brain(*original._brain);  // Crea una nueva copia profunda de `brain`
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Miau miau miau ..." << std::endl;
}