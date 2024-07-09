#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = copy._ideas[i];
    }
}

Brain& Brain::operator=(const Brain& original) {
    if (this != &original) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = original._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}