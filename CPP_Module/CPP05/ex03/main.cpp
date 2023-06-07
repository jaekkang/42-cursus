#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main(void) {
    try {
        Bureaucrat *b1 = new Bureaucrat("bur1", 1);
        Bureaucrat *b2 = new Bureaucrat("bur2", 150);
        Intern a;
        AForm *f1;
        AForm *f2;
        AForm *f3;

        std::srand(std::time(0));
        f1 = a.makeForm("PresidentialPardonForm", "form1");
        f2 = a.makeForm("RobotomyRequestForm", "form2");
        f3 = a.makeForm("ShrubberyCreationForm", "form3");
        try {
            b2->signForm(f1);
        } catch (AForm::BureauGradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            b1->executeForm(*f1);
            b1->executeForm(*f2);
            b1->executeForm(*f3);
        } catch (AForm::FormNotSigned &e) {
            std::cerr << e.what() << std::endl;
        }

        b1->signForm(f1);
        b1->signForm(f2);
        b1->signForm(f3);
        std::cout << "sign form & Try execute form" << std::endl;
        b1->executeForm(*f1);
        b1->executeForm(*f2);
        b1->executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;
        delete b1;

    } catch (Intern::NoMatchKey &e) {
        std::cerr << e.what() << std::endl;
    }
}
