#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <vector>

typedef std::vector<int> vector;
typedef std::deque<int> deque;
typedef vector::iterator vIter;
typedef deque::iterator dIter;

class PmergeMe {
 private:
  // variables
  std::vector<int> _base;
  vector _v;
  deque _d;

  clock_t _checkVectorTime;
  clock_t _checkDequeTime;

  int _jacobsthalIndex;
  int _jacobsthalNum[30];
  int _numOfInsert;

  // utils
  void printLine(std::string order);
  void printTime(clock_t time, std::string type);
  void setJacobsthalNum();
  int setContainers(const char **av);
  int getNextIndex(int index);

  // running methods
  void runVector();
  void runDeque();

  void comparePairVector(int num, int size);
  void comparePairDeque(int num, int size);

  void binarySearchInsertVector(vector &mainChain, vector &subChain, size_t idx,
                                size_t size);
  void binarySearchInsertDeque(deque &mainChain, deque &subChain, size_t idx,
                               size_t size);

  void recursionVector(size_t numOfElement, size_t sizeOfList);
  void recursionDeque(size_t numOfElement, size_t sizeOfList);

  void insertionVector(size_t numOfElement, size_t sizeOfList);
  void insertionDeque(size_t numOfElement, size_t sizeOfList);

  void setChainsVector(int num, int size, vector &main, vector &sub);
  void setChainsDeque(int num, int size, deque &main, deque &sub);

  // OCCF methods not need methods lock
  PmergeMe(const PmergeMe &obj);
  PmergeMe &operator=(const PmergeMe &obj);

 public:
  PmergeMe();
  ~PmergeMe();

  int run(char **av);
};

#endif