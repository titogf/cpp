#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);
        void attack(const std::string& target);
        void highFivesGuys(void);

        static const int defaultHit = 100;
		static const int defaultEnergy = 100;
		static const int defaultAttack = 30;
};

#endif