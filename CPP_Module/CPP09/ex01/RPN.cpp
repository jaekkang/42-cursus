#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj) { *this = obj; }

RPN &RPN::operator=(const RPN &obj) {
    if (this != &obj) {
        this->_numbers = obj._numbers;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::running(const char *str) {
    int a;
    int b;
    int result;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if (isdigit(str[i])) {
            this->_numbers.push(str[i] - '0');
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
                   str[i] == '/' || str[i] == '%') {
            if (this->_numbers.size() < 2) {
                std::cerr << "Error: not enough numbers" << std::endl;
                return 1;
            }
            a = this->_numbers.top();
            this->_numbers.pop();
            b = this->_numbers.top();
            this->_numbers.pop();
            if (str[i] == '+') {
                result = b + a;
            } else if (str[i] == '-') {
                result = b - a;
            } else if (str[i] == '*') {
                result = b * a;
            } else if (str[i] == '/') {
                if (a == 0 || b == 0) {
                    std::cerr << "Error: modulo by 0" << std::endl;
                    return 1;
                } else
                    result = b / a;
            } else if (str[i] == '%') {
                if (a == 0 || b == 0) {
                    std::cerr << "Error: modulo by 0" << std::endl;
                    return 1;
                } else
                    result = b % a;
            }
            this->_numbers.push(result);
        } else {
            std::cerr << "Error: invalid character" << std::endl;
            return 1;
        }
    }
    if (this->_numbers.size() != 1) {
        std::cerr << "Error: too many numbers" << std::endl;
        return 1;
    }
    std::cout << this->_numbers.top() << std::endl;
    return 0;
}