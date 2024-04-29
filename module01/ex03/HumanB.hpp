#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    private :
        std::string name;
    public :
        HumanB(std::string);
        ~HumanB();
        void    attack();
};

#endif