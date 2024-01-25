#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class PmergeMe {
 private:
  std::vector<int> _base;
  std::vector<int> _v;
  std::deque<int> _d;

  clock_t _checkTime;

  std::vector<std::pair<std::string, clock_t> > _times;

  void printLine(std::string order);

  int setContainers(const char **av);

  template <typename T>
  void merge(T &list, T &left, T &right) {
    size_t i = 0, j = 0, k = 0;
    size_t leftSize = left.size();
    size_t rightSize = right.size();

    while (i < leftSize && j < rightSize) {
      if (left[i] <= right[j]) {
        list[k] = left[i];
        ++i;
      } else {
        list[k] = right[j];
        ++j;
      }
      ++k;
    }

    while (i < leftSize) {
      list[k] = left[i];
      ++i;
      ++k;
    }

    while (j < rightSize) {
      list[k] = right[j];
      ++j;
      ++k;
    }
  }

  template <typename T>
  void fordjohnsonRecursion(T &list, size_t size) {
    if (size <= 1) return;
    size_t mid = size / 2;
    T left;
    T right;

    for (size_t i = 0; i < mid; i++) left.push_back(list[i]);
    for (size_t i = mid; i < size; i++) right.push_back(list[i]);
    fordjohnsonRecursion(left, mid);
    fordjohnsonRecursion(right, size - mid);

    merge(list, left, right);
  };

  template <typename T>
  void sortAndCheckTime(T &list, std::string listType) {
    _checkTime = clock();
    fordjohnsonRecursion(list, list.size());
    _checkTime = clock() - _checkTime;

    this->_times.push_back(std::make_pair(listType, _checkTime));
  };
  PmergeMe(const PmergeMe &obj);
  PmergeMe &operator=(const PmergeMe &obj);

 public:
  PmergeMe();
  ~PmergeMe();

  int run(char **av);
};

#endif