#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj) { *this = obj; }

RPN &RPN::operator=(const RPN &obj) {
    if (this != &obj) {
    }
    return *this;
}

RPN::~RPN() {}