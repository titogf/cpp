#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    int size = 10;
    Animal* a[size];
	//Animal pero;

    for (int i = 0; i < size; i++) {
		if (i < size / 2)
			a[i] = new Dog();
		else
			a[i] = new Cat();
	}
    for (int i = 0; i < size; i++) {
		std::cout << a[i]->getType() << std::endl;
        a[i]->makeSound();
	}
    for (int i = 0; i < size; i++) {
        delete a[i];
	}

    Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);

	std::cout << &cat1->getBrain() << std::endl;
	std::cout << &cat2->getBrain() << std::endl;
	
	delete cat1;
	delete cat2;

    return 0;
}