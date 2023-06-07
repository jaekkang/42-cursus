#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : AForm("RobotomyRequestForm", 72, 45) {
    this->setName(obj.getName());
    this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
    this->setSigned(obj.getSigned());
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        this->setName(obj.getName());
        this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
        this->setSigned(obj.getSigned());
    }
    return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false)
        throw(FormNotSigned());
    if (this->getExcuteGrade() > executor.getGrade()) {
        if (rand() % 2 == 0) {
            std::cout << executor.getName() << " execute success "
                      << this->getTarget() << std::endl;
        } else {
            std::cout << executor.getName() << " execute fail "
                      << this->getTarget() << std::endl;
        }
    } else {
        throw(GradeTooLowException());
    }
}