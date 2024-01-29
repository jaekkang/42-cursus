#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {
  *this = obj;
  return;
}

void PmergeMe::setJacobsthalNum() {
  _jacobsthalNum[0] = 1;
  _jacobsthalNum[1] = 3;

  for (int i = 2; i < 30; ++i)
    _jacobsthalNum[i] = _jacobsthalNum[i - 1] + 2 * _jacobsthalNum[i - 2];
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
  if (this != &obj) {
    this->_v = obj._v;
    this->_d = obj._d;
    this->_base = obj._base;
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

int PmergeMe::setContainers(const char **argv) {
  for (int i = 1; argv[i]; i++) {
    checkInput(argv[i]);

    this->_v.push_back(std::atoi(argv[i]));
    this->_d.push_back(std::atoi(argv[i]));
    this->_base.push_back(std::atoi(argv[i]));
  }
  return 0;
}

void PmergeMe::comparePairVector(int num, int size) {
  vIter iter = this->_v.begin();

  for (int i = 0; i <= num; i += 2) {
    vIter first = iter + i * size;
    vIter second = iter + (i + 1) * size;

    if (*first <= *second) std::swap_ranges(first, second, second);
  }
}

void PmergeMe::comparePairDeque(int num, int size) {
  dIter iter = this->_d.begin();

  for (int i = 0; i <= num; i += 2) {
    dIter first = iter + i * size;
    dIter second = iter + (i + 1) * size;

    if (*first <= *second) std::swap_ranges(first, second, second);
  }
}

void PmergeMe::setChainsVector(int num, int size, vector &main, vector &sub) {
  vIter it = _v.begin();

  for (int i = 0; i < num; ++i) {
    if (i == num - 1 || i % 2 == 1)
      sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
    else if (i % 2 == 0)
      main.insert(main.end(), it + i * size, it + (i + 1) * size);
  }
}

void PmergeMe::setChainsDeque(int num, int size, deque &main, deque &sub) {
  dIter it = _d.begin();

  for (int i = 0; i < num; ++i) {
    if (i == num - 1 || i % 2 == 1)
      sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
    else if (i % 2 == 0)
      main.insert(main.end(), it + i * size, it + (i + 1) * size);
  }
}

int PmergeMe::getNextIndex(int index) {
  if (index == 0) return 1;
  if (index == 1) return 3;
  if (index - 1 == _jacobsthalNum[_jacobsthalIndex]) {
    ++_jacobsthalIndex;
    return _jacobsthalNum[_jacobsthalIndex + 1];
  }
  return index - 1;
}

void PmergeMe::binarySearchInsertVector(vector &mainChain, vector &subChain,
                                        size_t idx, size_t size) {
  int left = 0;
  int right = idx + _numOfInsert;
  vIter subIt = subChain.begin() + idx * size;
  vIter mainIt = mainChain.begin();
  if (idx == 0) {
    mainChain.insert(mainIt, subIt, subIt + size);
    return;
  }

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mainChain[mid * size] < *subIt) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  mainChain.insert(mainIt + left * size, subIt, subIt + size);
  ++_numOfInsert;
}

void PmergeMe::binarySearchInsertDeque(deque &mainChain, deque &subChain,
                                       size_t idx, size_t size) {
  int left = 0;
  int right = idx + _numOfInsert;
  dIter subIt = subChain.begin() + idx * size;
  dIter mainIt = mainChain.begin();
  if (idx == 0) {
    mainChain.insert(mainIt, subIt, subIt + size);
    return;
  }

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mainChain[mid * size] < *subIt) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  mainChain.insert(mainIt + left * size, subIt, subIt + size);
  ++_numOfInsert;
}

void PmergeMe::insertionVector(size_t num, size_t size) {
  vector main;
  vector sub;
  int idx = 0;
  _jacobsthalIndex = 0;
  _numOfInsert = 0;
  int subChainNum = num / 2 + num % 2;

  setChainsVector(num, size, main, sub);
  for (int i = 0; i < subChainNum; ++i) {
    idx = getNextIndex(idx);
    if (idx >= subChainNum) idx = subChainNum;
    binarySearchInsertVector(main, sub, idx - 1, size);
  }
  for (size_t i = 0; i < main.size(); ++i) {
    _v[i] = main[i];
  }
}

void PmergeMe::insertionDeque(size_t num, size_t size) {
  deque main;
  deque sub;
  int idx = 0;
  _jacobsthalIndex = 0;
  _numOfInsert = 0;
  int subChainNum = num / 2 + num % 2;

  setChainsDeque(num, size, main, sub);
  for (int i = 0; i < subChainNum; ++i) {
    idx = getNextIndex(idx);
    if (idx >= subChainNum) idx = subChainNum;
    binarySearchInsertDeque(main, sub, idx - 1, size);
  }
  for (size_t i = 0; i < main.size(); ++i) {
    _d[i] = main[i];
  }
}

void PmergeMe::recursionVector(size_t numOfElement, size_t sizeOfPair) {
  if (numOfElement == 1) return;

  comparePairVector(numOfElement, sizeOfPair);
  recursionVector(numOfElement / 2, sizeOfPair * 2);
  insertionVector(numOfElement, sizeOfPair);
}

void PmergeMe::recursionDeque(size_t numOfElement, size_t sizeOfPair) {
  if (numOfElement == 1) return;

  comparePairDeque(numOfElement, sizeOfPair);
  recursionDeque(numOfElement / 2, sizeOfPair * 2);
  insertionDeque(numOfElement, sizeOfPair);
}

void PmergeMe::printTime(clock_t time, std::string type) {
  std::cout << "Time to process a range of " << _base.size()
            << " elements with std::" << type << " : " << time << " us"
            << std::endl;
}

void PmergeMe::runVector() {
  _checkVectorTime = clock();
  recursionVector(_v.size(), 1);
  _checkVectorTime = clock() - _checkVectorTime;
}

void PmergeMe::runDeque() {
  _checkDequeTime = clock();
  recursionVector(_v.size(), 1);
  _checkDequeTime = clock() - _checkDequeTime;
}

int PmergeMe::run(char **av) {
  try {
    setContainers((const char **)av);
    setJacobsthalNum();
    printLine("Before: ");
    runVector();
    runDeque();
    printLine("After: ");
    printTime(_checkVectorTime, "vector");
    printTime(_checkDequeTime, "deque");

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}