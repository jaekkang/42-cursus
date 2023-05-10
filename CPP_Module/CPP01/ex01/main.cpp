#include "Zombie.hpp"

int main(void) {
    Zombie *test2;

    test2 = zombieHorde(5, "test");
    for (int i = 0; i < 5; i++)
        test2[i].announce();
    delete[] test2;

    test2 = zombieHorde(3, "test");
    for (int i = 0; i < 3; i++)
        test2[i].announce();
    delete[] test2;

    test2 = zombieHorde(1, "test");
    for (int i = 0; i < 1; i++)
        test2[i].announce();
    delete[] test2;
}