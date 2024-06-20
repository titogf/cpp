#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal{
    public:
        Dog(void);
        ~Dog();

        void makeSound(void) const;
};

#endif