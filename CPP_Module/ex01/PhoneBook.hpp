#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
  private:
    Contact data[8];
    int _idx;

  public:
    PhoneBook();
    ~PhoneBook();

    void Add();
    void Search();
    int get_idx();
    void set_idx();
    void add_idx();
    Contact *get_data();
};

#endif