#include "Base.hpp"

Base *generate(void) {
    time_t ran = time(NULL);

    if (ran % 3 == 0) {
        std::cout << "selected A class" << std::endl;
        return (new A());
    } else if (ran % 3 == 1) {
        std::cout << "selected B class" << std::endl;
        return (new B());
    } else {
        std::cout << "selected C class" << std::endl;
        return (new C());
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "This Class is wrong" << std::endl;
}

void identify(Base &p) { identify(&p); }