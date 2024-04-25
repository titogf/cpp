#include "Zombie.hpp"

Zombie::Zombie(void){
    this->name = "Unnamed";
    std::cout << name << ": Im alive" << std::endl;
}

Zombie::Zombie(std::string name){
    this->name = name;
    std::cout << name << ": Im alive" << std::endl;
}

Zombie::~Zombie(void){
    std::cout << name << ": Im died" << std::endl;
}

void    Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
}