#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
  private:
    Contact _data[8];
    int _idx;

  public:
    PhoneBook();

    void add();
    void search();
    int getIdx();
    Contact *getData();
};

#endif