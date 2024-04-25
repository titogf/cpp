#include "Zombie.hpp"

int    main(void){
    Zombie zombie1("Gonzalo");
    Zombie zombie2("Alonso");
    Zombie* zombie3;
    Zombie* zombie4;

    std::cout << "---------- STACK MEMORY ----------" << std::endl;
    zombie1.announce();
    zombie2.announce();
    std::cout << "------------------------------" << std::endl;

    std::cout << "---------- HEAP MEMORY ----------" << std::endl;
    zombie3 = newZombie("Juan Alberto");
    zombie3->announce();
    delete (zombie3);
    zombie4 = newZombie("Perico Gutierrez");
    zombie4->announce();
    delete (zombie4);
    std::cout << "------------------------------" << std::endl;

    randomChump("Gustavo");

    return (0);
}