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