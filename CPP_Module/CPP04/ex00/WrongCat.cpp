#include "WrongCat.hpp"

WrongCat::WrongCat() {
    setType("WrongCat");
    std::cout << getType() << " class constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) { setType(obj.getType()); }

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    if (this != &obj) {
        setType(obj.getType());
    }
    return (*this);
}
WrongCat::~WrongCat() {
    std::cout << getType() << " class destructor called" << std::endl;
    setType("WrongAnimal");
}