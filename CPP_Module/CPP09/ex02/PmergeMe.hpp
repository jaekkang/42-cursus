#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>
class PmergeMe {
  private:
    std::vector<int> _v;
    std::list<int> _l;
    std::deque<int> _d;

    void printBeforeLine();
    void printAfterLine();

    int setContainers(const char **av);
    void fordjohnsonSort();

    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);

  public:
    PmergeMe();
    ~PmergeMe();

    int run(char **av);
};

#endif