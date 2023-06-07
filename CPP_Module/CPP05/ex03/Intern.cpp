#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) {
    if (this != &obj)
        *this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
    if (this != &obj) {
        *this = obj;
    }
    return (*this);
}
Intern::~Intern() {}

const char *Intern::NoMatchKey::what() const throw() {
    return ("There is no suitable form");
}

AForm *Intern::makeForm(std::string name, std::string target) {
    std::string base[3] = {"PresidentialPardonForm", "RobotomyRequestForm",
                           "ShrubberyCreationForm"};
    int key = -1;
    for (int i = 0; i < 3; i++) {
        if (base[i] == name) {
            key = i;
            break;
        }
    }
    if (key == -1)
        throw(NoMatchKey());
    else {
        try {
            std::cout << "Intern creates " << base[key] << std::endl;
            switch (key) {
            case 0:
                return (new PresidentialPardonForm(target));
            case 1:
                return (new RobotomyRequestForm(target));
            case 2:
                return (new ShrubberyCreationForm(target));
            }
        } catch (Intern::NoMatchKey &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return (NULL);
}