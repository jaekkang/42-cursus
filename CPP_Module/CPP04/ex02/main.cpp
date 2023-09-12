#include "AAnimal.hpp"
#include "ACat.hpp"
#include "ADog.hpp"

int main() {
    AAnimal *array[5];

    for (int i = 0; i < 5; ++i) {
        if (i % 2)
            array[i] = new ADog();
        else
            array[i] = new ACat();
    }

    for (int i = 0; i < 5; ++i) {
        array[i]->makeSound();
    }
}