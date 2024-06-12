#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "[" << _name << "] Constructor (ScavTrap) called" << std::endl;
    _hit = 100;
    _energy = 50;
    _attack = 20;
}

ScavTrap::~ScavTrap(void){
    std::cout << "[" << _name << "] Destructor (ScavTrap) called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energy == 0)
        std::cout  << "ScavTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << std::endl;
    else{
        _energy--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!"
        << " [" << _hit << " HP, " << _energy << " EP]" << std::endl;
    }
}

void ScavTrap::guardGate(void){
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode !" << std::endl;
}