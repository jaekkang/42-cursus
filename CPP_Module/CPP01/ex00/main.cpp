#include "Zombie.hpp"

int main(void) {
    Zombie newZome = Zombie();
    Zombie newZome1 = Zombie("zom1");
    Zombie *newZome2 = newZombie("zom2");
    Zombie *newZome3 = new Zombie("asdf");

    newZome.announce();
    newZome1.announce();
    newZome2->announce();
    newZome3->announce();

    delete newZome2;
    delete newZome3;

    randomChump("zombie1");
    randomChump("zombie2");
    randomChump("zombie3");
}