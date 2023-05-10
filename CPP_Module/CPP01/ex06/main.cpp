#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl;

    harl.flag = 0;
    if (ac != 2)
        return (0);
    switch (av[1][0]) {
    case 'D':
        harl.runDebug(std::string(av[1]));
    case 'I':
        harl.runInfo(std::string(av[1]));
    case 'W':
        harl.runWarning(std::string(av[1]));
    case 'E':
        harl.runError(std::string(av[1]));
        break;
    default:
        harl.putDefault();
        break;
    }
    return (0);
}