#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>

class Animal{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& original);
        virtual ~Animal();

        std::string getType(void) const;
        virtual void    makeSound(void) const = 0;
};
#endif