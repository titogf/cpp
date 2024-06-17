#include "FragTrap.hpp"

FragTrap::FragTrap(void){}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "[" << _name << "] Constructor (FragTrap) called" << std::endl;
    _hit = defaultHit;
    _energy = defaultEnergy;
    _attack = defaultAttack;
}

FragTrap::~FragTrap(void){std::cout << "[" << _name << "] Destructor (FragTrap) called" << std::endl;}

void FragTrap::attack(const std::string& target){
    if (_energy == 0)
        std::cout  << "FragTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << std::endl;
    else{
        _energy--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!"
        << " [" << _hit << " HP, " << _energy << " EP]" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " says high fives!" << std::endl;
}