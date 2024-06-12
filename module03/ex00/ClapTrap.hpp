#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        const std::string   _name;
        unsigned int        _hit;
        unsigned int        _energy;
        unsigned int        _attack;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator=(const ClapTrap& original);
        ~ClapTrap();

        std::string getName() const;
        unsigned int getHit() const;
        unsigned int getEnergy() const;
        unsigned int getAttack() const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif