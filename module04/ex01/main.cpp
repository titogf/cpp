#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    int size = 10;
    Animal* a[size];

	std::cout << "--------- CONSTRUCTORS CALLED --------" << std::endl;
    for (int i = 0; i < size; i++) {
		if (i < size / 2)
			a[i] = new Dog();
		else
			a[i] = new Cat();
	}
	std::cout << "--------- MAKE SOUND --------" << std::endl;
    for (int i = 0; i < size; i++) {
		std::cout << a[i]->getType() << std::endl;
        a[i]->makeSound();
	}
	std::cout << "--------- DESTRUCTORS CALLED --------" << std::endl;
    for (int i = 0; i < size; i++){
        delete a[i];}

	std::cout << "--------- CONSTRUCTORS CALLED --------" << std::endl;
    Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);

	std::cout << "--------- GET BRAIN --------" << std::endl;
	std::cout << &cat1->getBrain() << std::endl;
	std::cout << &cat2->getBrain() << std::endl;

	std::cout << "--------- DESTRUCTORS CALLED --------" << std::endl;
	delete cat1;
	delete cat2;

    return 0;
}