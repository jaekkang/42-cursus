#include "AAnimal.hpp"
#include "ACat.hpp"
#include "ADog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

int main() {
    AAnimal *array[5];
    Animal *animal;

    std::cout << std::endl;
    for (int i = 0; i < 5; ++i) {
        if (i % 2)
            array[i] = new ADog();
        else
            array[i] = new ACat();
    }
    std::cout << std::endl;
    animal = new Cat();

    for (int i = 0; i < 5; ++i) {
        array[i]->makeSound();
    }
    animal->makeSound();
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        delete array[i];
    }
    std::cout << std::endl;
    delete animal;
}