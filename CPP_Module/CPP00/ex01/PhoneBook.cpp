
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add() {
    this->get_data()[this->get_idx() % 8].AddContact();
    this->add_idx();
}

void PhoneBook::add_idx() { this->_idx += 1; }

void PhoneBook::set_idx() { this->_idx = 0; }

int PhoneBook::get_idx() { return (this->_idx); }

Contact *PhoneBook::get_data() { return (this->data); }

void PhoneBook::Search() {
    int number;

    std::cout << "|" << std::setw(10) << "Number";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    for (int i = 1; i < 9; i++) {
        std::cout << "|" << std::setw(10) << std::to_string(i);
        this->get_data()[i - 1].PrintContact();
    }
    std::cout << "Enter data number If you want to see detailed data"
              << std::endl;
    std::cin >> number;
    if (number < 9 && number > 0)
        this->get_data()[number - 1].PrintDetail();
    else {
        std::cout << "Error! invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
}

int main(void) {
    PhoneBook book;
    std::string cmd;

    book.set_idx();
    while (1) {
        if (std::cin.eof()) {
            exit(1);
        }
        std::cout << "Choose the command in [EXIT, ADD and SEARCH]"
                  << std::endl;
        std::cin >> cmd;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            book.Add();
        else if (cmd == "SEARCH")
            book.Search();
    }
    return (0);
}
