#include "PhoneBook.hpp"

void Contact::addContact() {
    std::cout << "first name :";
    std::cin >> this->_firstName;
    std::cout << "last name :";
    std::cin >> this->_lastName;
    std::cout << "nickname :";
    std::cin >> this->_nickname;
    std::cout << "phone number :";
    std::cin >> this->_phoneNumber;
    std::cout << "darkest secret :";
    std::cin >> this->_darkestSecret;
    std::cout << std::endl;
}

void Contact::printDetail() {
    std::cout << "This is the data of you chose" << std::endl;
    std::cout << "First Name :" << this->_firstName << std::endl;
    std::cout << "Last Name :" << this->_lastName << std::endl;
    std::cout << "Nickname :" << this->_nickname << std::endl;
    std::cout << "Phone Number :" << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret :" << this->_darkestSecret << std::endl;
}

std::string Contact::lengthCheck(std::string str) {
    std::string tmp;

    if (str.length() > 10) {
        tmp = str.substr(0, 9);
        tmp += ".";
        return (tmp);
    } else
        return (str);
}

void Contact::printContact() {
    std::cout << "|" << std::setw(10) << lengthCheck(this->_firstName);
    std::cout << "|" << std::setw(10) << lengthCheck(this->_lastName);
    std::cout << "|" << std::setw(10) << lengthCheck(this->_nickname) << "|"
              << std::endl;
}