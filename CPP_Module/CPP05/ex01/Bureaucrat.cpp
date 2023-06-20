#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : _name(obj.getName()), _grade(obj.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj) {
        *(const_cast<std::string *>(&this->_name)) = obj.getName(); 
        setGrade(obj.getGrade());
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &p) {
    os << p.getName() << ", bureaucrat grade " << p.getGrade();
    return (os);
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::signForm(Form *obj) {
    obj->beSigned(*this);
    if (obj->getSigned() == true)
        std::cout << this->_name << " signed " << obj->getName() << std::endl;
    else
        std::cout << this->_name << " couldn’t sign " << obj->getName()
                  << " because grade too row" << std::endl;
}

void Bureaucrat::downGrade() {
    try {
        if (this->_grade == 150)
            throw(GradeTooLowException());
        ++this->_grade;
    } catch (GradeTooLowException &e) {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::upGrade() {
    try {
        if (this->_grade == 1)
            throw(GradeTooHighException());
        --this->_grade;
    } catch (GradeTooHighException &e) {
        std::cerr << e.what() << '\n';
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("The grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("The grade was too low");
}

const std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::setGrade(int grade) { this->_grade = grade; }
