#include "ScalarConverter.hpp"
#include <iomanip>

std::string ScalarConverter::input;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
    this->input = obj.getInput();
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    if (this != &obj) {
        this->input = obj.getInput();
    }
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

std::string ScalarConverter::getInput() const { return input; }

const char *ScalarConverter::InvalidInput::what() const throw() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return 0;
}

bool isNumericString(const std::string &str) {
    size_t i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (i >= str.length())
        return false;

    int check = 0;
    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            check += 1;
            if (check > 1 || i + 1 == str.length())
                return false;
        }
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int check_char_invalid(double tmp) {
    int ret = static_cast<int>(tmp);
    return (ret > 31 && ret < 127);
}

int check_int_invalid(double tmp) {
    if (static_cast<int>(tmp) <= std::numeric_limits<int>::min() ||
        static_cast<int>(tmp) >= std::numeric_limits<int>::max()) {
        return false;
    }
    return true;
}

int myRound(const std::string &tmp) {
    size_t idx = tmp.find(".");
    if (idx != std::string::npos && idx < tmp.length() - 1) {
        int digit = tmp[idx + 1] - '0';
        if (digit >= 5)
            return std::stoi(tmp.substr(0, idx)) + 1;
        else {
            return std::stoi(tmp.substr(0, idx));
        }
    } else {
        return std::stoi(tmp);
    }
}

int checkOnlyZero(const std::string &tmp) {
    size_t idx = tmp.find(".");
    if (idx != std::string::npos) {
        for (size_t i = idx + 1; i < tmp.size(); i++) {
            if (tmp[i] != '0') {
                throw ScalarConverter::InvalidInput();
            }
        }
        return 1;
    }
    return 0;
}

int moreComma(std::string input) {
    int i = 0, check = 0;
    while (input[i]) {
        if (input[i] == '.')
            check += 1;
        if (check > 1)
            throw ScalarConverter::InvalidInput();
        i++;
    }
    return 0;
}

int checkInput(std::string input) {
    int d = 0, a = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
            return 0;
        if (isdigit(input[i]))
            d += 1;
        if (isalpha(input[i]) && input[i] != 'f')
            a += 1;
    }
    if (a > 0 && d > 0)
        return (0);
    return 1;
}

int check_float(std::string input) {
    size_t pos;
    int f = 0;

    pos = input.find('.');
    if (input[input.length() - 1] != 'f' || pos == std::string::npos)
        return 0;
    for (size_t i = pos; pos < input.length(); i++) {
        if (isalpha(input[i]) && input[i] != 'f')
            return 0;
        if (input[i] == 'f') {
            f += 1;
            if (f > 1)
                return 0;
        }
    }
    return 1;
}

void ScalarConverter::convert(std::string input) const {
    std::string::size_type pos;
    double tmp;

    if (input == "-inf" || input == "+inf" || input == "inf" ||
        input == "-inff" || input == "+inff" || input == "nanf" ||
        input == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (input == "-inf" || input == "+inf" || input == "inf" ||
            input == "nan") {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        } else {
            double tmp = std::stod(input);
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << (tmp > 0 ? "+" : "") << tmp << std::endl;
        }
        return;
    }

    try {
        char c = input[0];

        if (input.length() > 2 && isalpha(input[0]) && isalpha(input[1]))
            throw ScalarConverter::InvalidInput();
        if (input.length() == 1 && c != '.' && !isnumber(input[0])) {
            if (std::isalpha(c) || std::isprint(c)) {
                std::cout << "char: '" << c << "'" << std::endl;
                std::cout << "int: " << static_cast<int>(c) << std::endl;
                std::cout << "float: " << static_cast<float>(c) << ".0f"
                          << std::endl;
                std::cout << "double: " << static_cast<double>(c) << ".0"
                          << std::endl;
            }
            return;
        }
        if (c == '.') {
            if (input.length() == 1)
                throw ScalarConverter::InvalidInput();
            if (checkOnlyZero(input)) {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: 0.0f" << std::endl;
                std::cout << "double: 0.0" << std::endl;
                return;
            }
        } else if (moreComma(input) || (input.find('.') == std::string::npos &&
                                        !checkInput(input))) {
            throw ScalarConverter::InvalidInput();
        } else if (input != "nan" && input != "nanf" &&
                   isNumericString(input)) {

            tmp = std::stod(input);
            if (check_char_invalid(tmp)) {
                std::cout << "char: '" << static_cast<char>(tmp) << "'"
                          << std::endl;
            } else if (static_cast<int>(tmp) >= 0 &&
                       static_cast<int>(tmp) <= 127) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }
            if (check_int_invalid(tmp)) {
                std::cout << "int: " << static_cast<int>(round(tmp))
                          << std::endl;
            } else {
                std::cout << "int: impossible" << std::endl;
            }
        } else if ((pos = input.find('.')) != std::string::npos) {
            if (!checkInput(input))
                throw ScalarConverter::InvalidInput();
            if ((!checkInput(input) && input[input.length() - 1] != 'f') ||
                input[input.length() - 1] == '.' ||
                input[input.find('.') + 1] == 'f') {
                throw ScalarConverter::InvalidInput();
            }
            if (check_char_invalid(std::stod(input)) && !check_float(input)) {
                std::cout << "char: '" << static_cast<char>(std::stod(input))
                          << "'" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }
            std::cout << "int: " << myRound(input) << std::endl;
        }

        if ((pos = input.find('.')) == std::string::npos && input != "nan" &&
            input != "nanf" && std::stod(input)) {

            std::cout << "float: " << std::stod(input) << ".0f" << std::endl;
            std::cout << "double: " << std::stod(input) << ".0" << std::endl;
        } else {
            std::string fpos;

            tmp = std::stod(input);
            fpos = input.substr(input.find('.') + 1);
            if (input[input.length() - 1] == 'f') {
                std::cout << "float: " << std::fixed
                          << std::setprecision(fpos.length() - 1) << tmp << "f"
                          << std::endl;
                std::cout << "double: " << tmp << std::endl;
            } else {
                std::cout << "float: " << std::fixed
                          << std::setprecision(fpos.length()) << tmp << "f"
                          << std::endl;
                std::cout << "double: " << tmp << std::endl;
            }
        }

    } catch (ScalarConverter::InvalidInput &e) {
        e.what();
    }
}