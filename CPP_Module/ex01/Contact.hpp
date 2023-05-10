#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

class Contact {
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

  public:
    void printContact();
    void printDetail();
    void addContact();

    std::string lengthCheck(std::string str);
};

#endif