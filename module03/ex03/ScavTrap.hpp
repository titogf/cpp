#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ~ScavTrap(void);

        void attack(const std::string& target);
        void guardGate(void);

        static const int defaultHit = 100;
		static const int defaultEnergy = 50;
		static const int defaultAttack = 20;
};

#endif