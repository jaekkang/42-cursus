#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat tmp0("tmp0", 0);
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;
    try {
        Bureaucrat tmp1("tmp1", 1);
        Bureaucrat tmp2("tmp2", 75);
        Bureaucrat tmp3("tmp3", 150);

        tmp1.upGrade();

        tmp3.downGrade();

        std::cout << tmp1 << std::endl;
        std::cout << tmp2 << std::endl;
        std::cout << tmp3 << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    }
}
