#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
  private:
    std::stack<int> _numbers;

  public:
    RPN();
    ~RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);

    int running(const char *str);
};

#endif