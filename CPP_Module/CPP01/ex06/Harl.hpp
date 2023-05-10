#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

  public:
    int flag;
    void runDebug(std::string command);
    void runInfo(std::string command);
    void runWarning(std::string command);
    void runError(std::string command);
    void putDefault(void);
};

#endif