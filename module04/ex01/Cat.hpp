#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal{
    private:
        Brain* _brain;
    public:
        Cat(void);
        Cat(const Cat& copy);
        Cat& operator=(const Cat& original);
        ~Cat();

        void makeSound(void) const;
};

#endif