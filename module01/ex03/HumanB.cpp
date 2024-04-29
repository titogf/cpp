#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::attack(){
    if (_weapon == NULL)
        std::cout << name << " can't attack because is unarmed !" << std::endl;
    else
        std::cout << name << " attacks with their " << (*_weapon).getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;
}