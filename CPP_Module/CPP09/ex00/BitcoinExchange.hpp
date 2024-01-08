#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
 private:
  std::map<std::string, float> _bitcoinDatas;

  void checkFile();
  void checkInputFile(char* file);
  void checkInfo(std::string info);
  int checkDate(const std::string& dates);
  int checkValue(const std::string& str);

  bool isValidateDate(std::string str);
  bool isValidateValue(std::string str);
  bool isValidateInput(std::string str);

  void printBitcoinDatas();
  void printBit(std::string date, float n);
  void match(char* file);

 public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const& src);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);
  ~BitcoinExchange();

  void run(char* file);

  class Error : public std::exception {
   public:
    Error(std::string msg);
    const char* what() const throw();
  };
};

#endif