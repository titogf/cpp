#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("Alberto");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("fernando");
    a.beRepaired(3);
    a.takeDamage(15);
    a.guardGate();

    return 0;
}