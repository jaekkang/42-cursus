#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN [expression]" << std::endl;
        return 1;
    }
    RPN rpn;

    rpn.running(av[1]);
    return 0;
}
