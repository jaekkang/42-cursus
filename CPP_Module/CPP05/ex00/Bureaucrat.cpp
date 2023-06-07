#include "Bureaucrat.hpp"

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
        setGrade(obj.getGrade());
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &p) {
    os << p.getName() << ", bureaucrat grade " << p.getGrade();
    return (os);
}

Bureaucrat::~Bureaucrat() {}

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
    return ("The grade is too low");
}

const std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::setGrade(int grade) { this->_grade = grade; }