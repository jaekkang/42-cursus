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

void PmergeMe::printLine(std::string order) {
    std::cout << order;
    for (size_t i = 0; i < this->_v.size(); i++) {
        std::cout << this->_v[i];
        if (i + 1 < this->_v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int PmergeMe::setContainers(const char **argv) {
    int tmp;

    for (int i = 1; argv[i]; i++) {
        tmp = std::atoi(argv[i]);
        if (isdigit(tmp) != 0)
            throw std::runtime_error("Error: invalid character");
        this->_v.push_back(tmp);
        this->_d.push_back(tmp);
    }
    return 0;
}

int PmergeMe::run(char **av) {
    setContainers((const char **)av);

    printLine("Before: ");
    sortAndCheckTime(this->_v, "vector");
    sortAndCheckTime(this->_d, "deque");
    printLine("After: ");

    double usTime;

    for (size_t i = 0; i < this->_time.size(); i++) {
        usTime = _time[i].second;
        std::cout << "Time to process a range of " << _v.size()
                  << " elements with std::" << _time[i].first << " : " << usTime
                  << " us" << std::endl;
    }
    return 0;
}