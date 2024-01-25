#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {
  *this = obj;
  return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
  if (this != &obj) {
    this->_v = obj._v;
    this->_d = obj._d;
    this->_base = obj._base;
    this->_times = obj._times;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printLine(std::string order) {
  std::cout << order;
  for (size_t i = 0; i < this->_v.size(); i++) {
    std::cout << this->_v[i];
    if (i + 1 < this->_v.size()) std::cout << " ";
  }
  std::cout << std::endl;
}

void checkInput(const char *input) {
  long tmp = std::atol(input);

  if (tmp > 2147483648) {
    throw std::runtime_error("Error: number too big");
  }

  if (std::strchr(input, '.') != nullptr) {
    throw std::runtime_error("Error: decimal numbers not allowed");
  }

  for (size_t i = 0; i < std::strlen(input); i++) {
    if (std::isdigit(input[i]) == 0) {
      throw std::runtime_error("Error: non-digit character in input");
    }
  }
}

// int PmergeMe::jacobsthal(int n) {
//   if (n == 0) return 0;
//   if (n == 1) return 1;
//   return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }

// void PmergeMe::MakeJacobArr() {
//   size_t remainSize;
//   size_t jacobsthalIdx;
//   int index;

//   remainSize = this->_base.size();
//   index = 3;

//   while ((jacobsthalIdx = this->jacobsthal(index)) < remainSize) {
//     this->jacobArr.push_back(jacobsthalIdx);
//     index++;
//   }
// }

int PmergeMe::setContainers(const char **argv) {
  for (int i = 1; argv[i]; i++) {
    checkInput(argv[i]);

    this->_v.push_back(std::atoi(argv[i]));
    this->_d.push_back(std::atoi(argv[i]));
    this->_base.push_back(std::atoi(argv[i]));
  }
  return 0;
}

int PmergeMe::run(char **av) {
  try {
    setContainers((const char **)av);

    printLine("Before: ");
    sortAndCheckTime(this->_v, "vector");
    sortAndCheckTime(this->_d, "deque");
    printLine("After: ");

    for (size_t i = 0; i < this->_times.size(); i++) {
      std::cout << "Time to process a range of " << _base.size()
                << " elements with std::" << _times[i].first << " : "
                << _times[i].second << " us" << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}