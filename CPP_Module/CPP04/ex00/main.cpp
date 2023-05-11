#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *tmp = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << tmp->getType() << " " << std::endl;

    std::cout << std::endl;

    meta->makeSound();
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    tmp->makeSound();

    std::cout << std::endl;
    delete meta;
    delete j;
    delete i;
    delete tmp;

    return 0;
}