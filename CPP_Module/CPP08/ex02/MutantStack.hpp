#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <typename T>

class MutantStack : public std::stack<T> {
  private:
  public:
    MutantStack(){};
    MutantStack(const MutantStack &other) { *this = other; };
    MutantStack &operator=(const MutantStack &other) {
        *this = other;
        return *this;
    };
    ~MutantStack(){};

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    iterator rbegin() { return this->c.rbegin(); }
    iterator rend() { return this->c.rend(); }
};

#endif