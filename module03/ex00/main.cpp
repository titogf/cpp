#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Gonzalo");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("fernando");
    a.beRepaired(3);
    a.takeDamage(15);

    return 0;
}