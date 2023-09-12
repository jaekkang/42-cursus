#include "WrongCat.hpp"

WrongCat::WrongCat() { setType("Cat"); }

WrongCat::WrongCat(const WrongCat &obj) { _type = obj.getType(); }

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    if (this != &obj) {
        _type = obj.getType();
    }
    return (*this);
}
WrongCat::~WrongCat() {}