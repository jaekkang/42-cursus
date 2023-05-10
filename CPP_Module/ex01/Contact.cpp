#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::AddContact() {
    std::cout << "first name :" << std::endl;
    std::cin >> this->_first_name;
    std::cout << "last name :";
    std::cin >> this->_last_name;
    std::cout << "nickname :";
    std::cin >> this->_nickname;
    std::cout << "phone number :";
    std::cin >> this->_phone_number;
    std::cout << "darkest secret :";
    std::cin >> this->_darkest_secret;
    std::cout << std::endl;
}

void Contact::PrintDetail() {
    std::cout << "This is the data of you chose" << std::endl;
    std::cout << "First Name :" << this->get_fname() << std::endl;
    std::cout << "Last Name :" << this->get_lname() << std::endl;
    std::cout << "Nickname :" << this->get_nname() << std::endl;
    std::cout << "Phone Number :" << this->get_pnumber() << std::endl;
    std::cout << "Darkest Secret :" << this->get_secret() << std::endl;
}

std::string Contact::LengthCheck(std::string str) {
    std::string tmp;

    if (str.length() > 10) {
        tmp = str.substr(0, 9);
        tmp += ".";
        return (tmp);
    } else
        return (str);
}

std::string Contact::get_fname(void) { return (this->_first_name); }

std::string Contact::get_lname(void) { return (this->_last_name); }

std::string Contact::get_nname(void) { return (this->_nickname); }

std::string Contact::get_pnumber(void) { return (this->_phone_number); }

std::string Contact::get_secret(void) { return (this->_darkest_secret); }

void Contact::PrintContact() {
    std::cout << "|" << std::setw(10) << LengthCheck(this->_first_name);
    std::cout << "|" << std::setw(10) << LengthCheck(this->get_lname());
    std::cout << "|" << std::setw(10) << LengthCheck(this->get_nname()) << "|"
              << std::endl;
}