#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5) {
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &obj)
    : AForm("PresidentialPardonForm", 25, 5) {
    this->setName(obj.getName());
    this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
    this->setSigned(obj.getSigned());
    this->setTarget(obj.getTarget());
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        this->setName(obj.getName());
        this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
        this->setSigned(obj.getSigned());
        this->setTarget(obj.getTarget());
    }
    return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false) {
        throw(FormNotSigned());
    } else if (this->getExcuteGrade() > executor.getGrade()) {
        std::cout << this->getTarget() << " Pardoned by Zaphod Beeblebrox."
                  << std::endl;
    } else {
        throw(GradeTooLowException());
    }
}