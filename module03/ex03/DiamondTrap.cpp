#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    _hit = FragTrap::defaultHit;
    _energy = ScavTrap::defaultEnergy;
    _attack = FragTrap::defaultAttack;
    std::cout << "[" << _name << "] Constructor (DiamondTrap) called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    _name = copy._name;
    ClapTrap::_name = (_name + "_clap_name");
    _hit = copy._hit;
    _energy = copy._energy;
    _attack = copy._attack;
    std::cout << "[" << _name << "] copy (DiamondTrap) called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    if (this != &original) {
        _name = original._name;
        ClapTrap::_name = (_name + "_clap_name");
        _hit = original._hit;
        _energy = original._energy;
        _attack = original._attack;
    }
    std::cout << "[" << _name << "]" << " operator (DiamondTrap) called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "[" << _name << "] Destructor (DiamondTrap) called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << "\nClapTrap name: " << ClapTrap::_name << std::endl;
}
