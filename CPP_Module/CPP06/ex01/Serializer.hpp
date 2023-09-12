#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer {
  private:
    Data *_value;

  public:
    Serializer(Data *obj);
    ~Serializer();
    Serializer(const Serializer &obj);
    Serializer &operator=(const Serializer &obj);

    uintptr_t serialize(const Serializer *ptr);
    Serializer *deserialize(uintptr_t raw);

    const Data *getValue() const;

    void setValue(Data *value);
};

#endif