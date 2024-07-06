#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDeepCopy() {
    Dog originalDog;
    originalDog._brain->setIdea(0, "Chase the ball"); // Asumiendo que tienes un método setIdea en Brain
    originalDog._brain->setIdea(1, "Bark at the mailman");

    Dog copiedDog = originalDog; // Invoca el constructor de copia

    // Cambiar una idea en la copia
    copiedDog._brain->setIdea(0, "Sleep all day");

    // Verificar que el original no se ve afectado por los cambios en la copia
    std::cout << "Original Dog's Brain Idea 0: " << originalDog._brain->getIdea(0) << std::endl;
    std::cout << "Copied Dog's Brain Idea 0: " << copiedDog._brain->getIdea(0) << std::endl;

    // Esperar que las ideas sean diferentes si la copia es profunda
}

int main()
{
    int size = 10;
    Animal* a[size];

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
    for (int i = 0; i < size; i++)
        delete a[i];

    testDeepCopy();

    return 0;
}