#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {
  private:
  public:
    PmergeMe(/* args*/);
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
};

#endif