#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat tmp1("tmp1", 149);
        Bureaucrat tmp3("tmp3", 1);
        Form form1("form1", 10, 10);

        std::cout << form1 << std::endl;

        tmp1.signForm(&form1);
        tmp3.signForm(&form1);
        std::cout << tmp1 << std::endl;
        std::cout << tmp3 << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
}
