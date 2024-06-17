#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("Alberto");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("fernando");
    a.beRepaired(3);
    a.takeDamage(15);
    a.whoAmI();

    return 0;
}