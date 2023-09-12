#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int excuteGrade)
    : _name(name), _signGrade(signGrade), _excuteGrade(excuteGrade) {
    _isSigned = false;
    if (signGrade < 1 || excuteGrade < 1)
        throw(GradeTooHighException());
    else if (signGrade > 150 || excuteGrade > 150)
        throw(GradeTooLowException());
}

Form::Form(const Form &obj)
    : _name(obj.getName()), _signGrade(obj.getSignGrade()),
      _excuteGrade(obj.getExcuteGrade()) {
    this->_isSigned = obj.getSigned();
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj) {
        *(const_cast<std::string *>(&this->_name)) = obj.getName();
        *(const_cast<int *>(&this->_signGrade)) = obj.getSignGrade();
        *(const_cast<int *>(&this->_excuteGrade)) = obj.getExcuteGrade();
        this->_isSigned = obj.getSigned();
    }
    return (*this);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() < 1)
        throw(Form::GradeTooHighException());
    else if (obj.getGrade() > 150)
        throw(Form::GradeTooLowException());
    if (this->_signGrade > obj.getGrade())
        this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("From Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("From Grade Too Low");
}

const std::string Form::getName() const { return (this->_name); }

bool Form::getSigned() const { return (this->_isSigned); }

int Form::getSignGrade() const { return (this->_signGrade); }

int Form::getExcuteGrade() const { return (this->_excuteGrade); }

void Form::setSigned(bool isSigned) { this->_isSigned = isSigned; }

std::ostream &operator<<(std::ostream &os, Form &p) {
    os << p.getName() << ", execute grade " << p.getExcuteGrade()
       << ", sign grade " << p.getSignGrade();
    return (os);
}