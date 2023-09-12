#include "Serializer.hpp"

Serializer::Serializer(Data *obj) { this->_value = obj; }

Serializer::Serializer(const Serializer &obj) { 
    if (this->_value) {
        delete _value;
    }
        _value = new Data(*(obj._value));
 }

Serializer &Serializer::operator=(const Serializer &obj) {
    if (this != &obj) {
        if (this->_value) {
            delete _value;
        }
        _value = new Data(*(obj._value));
    }
    return (*this);
}

Serializer::~Serializer() {
    if (this->_value)
        delete _value;
}

uintptr_t Serializer::serialize(const Serializer *ptr) {
    std::cout << "before Data ptr : " << ptr << std::endl;
    std::cout << "serialize after Data ptr : "
              << reinterpret_cast<uintptr_t>(ptr) << std::endl;
    return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer *Serializer::deserialize(uintptr_t raw) {
    std::cout << "before Data uintptr_t raw : " << raw << std::endl;
    std::cout << "deserialize after Data raw : "
              << reinterpret_cast<Serializer *>(raw) << std::endl;
    return reinterpret_cast<Serializer *>(raw);
}

const Data *Serializer::getValue() const { return _value; }

void Serializer::setValue(Data *value) { this->_value = value; }