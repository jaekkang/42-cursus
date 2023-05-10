
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { this->_idx = 0; }

void PhoneBook::add() {
    this->_data[this->_idx % 8].addContact();
    this->_idx += 1;
}

int PhoneBook::getIdx() { return (this->_idx); }

Contact *PhoneBook::getData() { return (this->_data); }

void PhoneBook::search() {
    int number;

    std::cout << "|" << std::setw(10) << "Number";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    for (int i = 1; i < 9; i++) {
        std::cout << "|" << std::setw(10) << std::to_string(i);
        this->_data[i - 1].printContact();
    }
    std::cout << "Enter data number If you want to see detailed data"
              << std::endl;
    std::cin >> number;
    if (number < 9 && number > 0)
        this->_data[number - 1].printDetail();
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
            book.add();
        else if (cmd == "SEARCH")
            book.search();
    }
    return (0);
}
