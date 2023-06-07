#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

int main(void) {
    ShrubberyCreationForm form1("form1");
    RobotomyRequestForm form2("form2");
    PresidentialPardonForm form3("form3");
    Bureaucrat b1("bur1", 1);
    Bureaucrat b2("bur2", 150);

    std::srand(std::time(0));

    try {
        b2.signForm(&form1);
    } catch (AForm::BureauGradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::boolalpha << form2.getSigned() << std::endl;
    b1.signForm(&form2);
    std::cout << std::boolalpha << form3.getSigned() << std::endl;
    b1.signForm(&form3);

    std::cout << std::boolalpha << form2.getSigned() << std::endl;
    std::cout << std::boolalpha << form3.getSigned() << std::endl;

    try {
        b1.executeForm(form1);
    } catch (AForm::FormNotSigned &e) {
        std::cerr << e.what() << std::endl;
    }

    b1.executeForm(form2);
    b1.executeForm(form3);
    try {
        b2.executeForm(form3);
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
}
