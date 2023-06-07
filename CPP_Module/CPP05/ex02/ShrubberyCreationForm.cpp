#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    : AForm("ShrubberyCreationForm", 145, 137) {
    this->setName(obj.getName());
    this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
    this->setSigned(obj.getSigned());
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        this->setName(obj.getName());
        this->setGrade(obj.getSignGrade(), obj.getExcuteGrade());
        this->setSigned(obj.getSigned());
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false) {
        throw(FormNotSigned());
    } else if (this->getExcuteGrade() > executor.getGrade()) {
        std::ofstream tmp(this->getTarget() + "_shrubbery");

        tmp << "    *\n   /.\\\n  /o..\\\n  /..o\\\n /.o..o\\\n "
               "/...o.\\\n/..o....\\\n^^^[_]^^^\n"
            << std::endl;
        tmp.close();
    } else {
        throw(GradeTooLowException());
    }
}