#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    *this = obj;
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    if (this != &obj) {
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printBeforeLine() {
    std::cout << "Before: ";
    for (size_t i = 0; i < this->_v.size(); i++) {
        std::cout << this->_v[i];
        if (i + 1 < this->_v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfterLine() {
    std::cout << "After: ";
    for (size_t i = 0; i < this->_v.size(); i++) {
        std::cout << this->_v[i];
        if (i + 1 < this->_v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fordjohnsonSort() { std::cout << "sorting" << std::endl; }

int PmergeMe::run(char **av) {
    setContainers((const char **)av);

    printBeforeLine();
    fordjohnsonSort();
    printAfterLine();
    return 0;
}

int PmergeMe::setContainers(const char **argv) {
    int tmp;

    for (int i = 1; argv[i]; i++) {
        tmp = std::atoi(argv[i]);
        if (isdigit(tmp) != 0)
            throw std::runtime_error("Error: invalid character");
        this->_v.push_back(tmp);
        this->_l.push_back(tmp);
        this->_d.push_back(tmp);
    }
    return 0;
}