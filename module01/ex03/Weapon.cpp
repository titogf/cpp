#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->_type = type;
}

Weapon::~Weapon(){}

void Weapon::setType(std::string type){
    this->_type = type;
}

const std::string& Weapon::getType(void) const{
    return (_type);
}