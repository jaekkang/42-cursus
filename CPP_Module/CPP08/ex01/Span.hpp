#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
  private:
    std::vector<int> _v;
    size_t _size;

  public:
    Span(const size_t &size);
    ~Span();
    Span(const Span &obj);
    Span &operator=(const Span &obj);

    void addNumber(const int &n);
    int shortestSpan();
    int longestSpan();

    class ArgumentException : public std::exception {
      public:
        virtual const char *what() const throw() {
            return ("Error: Argument exception");
        }
    };

    class FullException : public std::exception {
      public:
        virtual const char *what() const throw() {
            return ("Error: Container is full");
        }
    };
};

#endif