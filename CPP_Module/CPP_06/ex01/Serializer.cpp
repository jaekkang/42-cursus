#include "Serializer.hpp"

Serializer::Serializer(Data *obj) { this->_value = obj; }

Serializer::Serializer(const Serializer &obj) { new (this)(Serializer)(obj); }

Serializer &Serializer::operator=(const Serializer &obj) {
    new (this)(Serializer)(obj);
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Serializer *ptr) {
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