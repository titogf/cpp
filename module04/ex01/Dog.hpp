#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal{
    private:
        Brain* _brain;
    public:
        Dog(void);
        Dog(const Dog& copy);
        Dog& operator=(const Dog& original);
        ~Dog();

        void makeSound(void) const;
        const Brain& getBrain() const;
};

#endif