#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::string str;
    Animal *array[10];
    Dog *newdog = new Dog();

    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            array[i] = new Dog();
        } else {
            array[i] = new Cat();
        }
    }
    std::cout << std::endl;
    std::cout << "check =>" << newdog->getBrain()->getIdea(99) << std::endl;
    delete newdog;
    for (int i = 0; i < 10; i++) {
        array[i]->makeSound();
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        delete array[i];
    }
}