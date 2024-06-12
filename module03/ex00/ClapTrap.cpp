#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name)
{
    std::cout << "[" << _name << "] Constructor called" << std::endl;
    _hit = 10;
    _energy = 10;
    _attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy): _name(copy.getName())
{
    std::cout << "[" << _name << "] copy called" << std::endl;
    _hit = copy.getHit();
    _energy = copy.getEnergy();
    _attack = copy.getAttack();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
    if (this != &original){
        _hit = original.getHit();
        _energy = original.getEnergy();
        _attack = original.getAttack();
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "[" << _name << "] Destructor called" << std::endl;
}

std::string ClapTrap::getName() const {return (_name);}

unsigned int ClapTrap::getHit() const {return (_hit);}

unsigned int ClapTrap::getEnergy() const {return (_energy);}

unsigned int ClapTrap::getAttack() const {return (_attack);}

void ClapTrap::attack(const std::string& target)
{
    if (_energy == 0)
        std::cout  << "ClapTrap " << _name << " wants to attack " << target << " but it has 0 energy points !" << std::endl;
    else{
        _energy--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!"
        << " [" << _hit << " HP, " << _energy << " EP]" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit <= amount)
        _hit = 0;
    else
        _hit -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!"
    << " [" << _hit << " HP, " << _energy << " EP]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energy == 0)
        std::cout  << "ClapTrap " << _name << " wants to be repaired but it has 0 energy points !" << std::endl;
    else {
        _hit += amount;
        _energy -= 1;
        std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points!"
        << " [" << _hit << " HP, " << _energy << " EP]" << std::endl;
    }
}