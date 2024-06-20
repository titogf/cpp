#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal{
    public:
        Cat(void);
        ~Cat();

        void makeSound(void) const;
};

#endif