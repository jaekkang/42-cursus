#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int excuteGrade)
    : _name(name), _signGrade(signGrade), _excuteGrade(excuteGrade) {
    _isSigned = false;
    if (signGrade < 1 || excuteGrade < 1)
        throw(GradeTooHighException());
    else if (signGrade > 150 || excuteGrade > 150)
        throw(GradeTooLowException());
}

AForm::AForm(const AForm &obj)
    : _name(obj.getName()), _signGrade(obj.getSignGrade()),
      _excuteGrade(obj.getExcuteGrade()) {
    this->_isSigned = obj.getSigned();
}

AForm &AForm::operator=(const AForm &obj) {
    if (this != &obj) {
        *(const_cast<std::string *>(&this->_name)) = obj.getName();
        *(const_cast<int *>(&this->_signGrade)) = obj.getSignGrade();
        *(const_cast<int *>(&this->_excuteGrade)) = obj.getExcuteGrade();
        this->_isSigned = obj.getSigned();
    }
    return (*this);
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() < 1)
        throw(AForm::GradeTooHighException());
    else if (obj.getGrade() > 150)
        throw(AForm::GradeTooLowException());
    else if (this->_signGrade > obj.getGrade())
        this->_isSigned = true;
    else if (this->_signGrade < obj.getGrade())
        throw(AForm::BureauGradeTooLowException());
}

const char *AForm::FormNotSigned::what() const throw() {
    return ("This Form, Not signed");
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Form Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Form Grade Too Low");
}

const char *AForm::BureauGradeTooLowException::what() const throw() {
    return ("Bureaucrat Grade Too Low");
}

const std::string AForm::getName() const { return (this->_name); }

bool AForm::getSigned() const { return (this->_isSigned); }

int AForm::getSignGrade() const { return (this->_signGrade); }

int AForm::getExcuteGrade() const { return (this->_excuteGrade); }

const std::string AForm::getTarget() const { return (this->_target); }

void AForm::setTarget(std::string target) { this->_target = target; }

void AForm::setName(std::string name) {
    *(const_cast<std::string *>(&this->_name)) = name;
}

void AForm::setSigned(bool isSigned) { this->_isSigned = isSigned; }

void AForm::setGrade(int signGrade, int excuteGrade) {
    if (signGrade < 1 || excuteGrade < 1)
        throw(AForm::GradeTooHighException());
    else if (signGrade > 150 || excuteGrade > 150)
        throw(AForm::GradeTooLowException());
    *(const_cast<int *>(&this->_signGrade)) = signGrade;
    *(const_cast<int *>(&this->_excuteGrade)) = excuteGrade;
}

std::ostream &operator<<(std::ostream &os, AForm &p) {
    os << p.getName() << ", execute grade " << p.getExcuteGrade()
       << ", sign grade " << p.getSignGrade();
    return (os);
}