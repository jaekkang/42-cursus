#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

void BitcoinExchange::checkInputFile(char *file) {
  std::ifstream fs;
  std::string str;
  std::string prefix = "\"./" + std::string(file);

  fs.open(file);
  if (!fs.is_open()) {
    throw BitcoinExchange::Error(prefix + "\"" + " not found");
  }
  if (std::getline(fs, str).eof()) {
    throw BitcoinExchange::Error(prefix + "\"" + " is empty");
  }
  if (str.compare("data | value") != 0) {
    throw BitcoinExchange::Error(prefix + "\"" + " is format invalid");
  }

  str.erase();
  fs.close();
}

void BitcoinExchange::checkFile() {
  std::ifstream csv("data.csv");
  size_t size;
  float value;
  std::string line;

  if (!csv.is_open()) {
    throw BitcoinExchange::Error("data.csv not found");
  }
  if (std::getline(csv, line).eof()) {
    throw BitcoinExchange::Error("data.csv is empty");
  }

  while (std::getline(csv, line)) {
    if (line != "date,exchange_rate") {
      size = line.find(',');
      if (isValidateDate(line.substr(0, size)) == false) {
        throw BitcoinExchange::Error("data.csv date is invalid");
      }

      if (isValidateValue(line.substr(size + 1, line.length())) == false) {
        throw BitcoinExchange::Error("data.csv value is invalid");
      }
      std::istringstream(line.substr(size + 1, line.length())) >> value;
      _bitcoinDatas[line.substr(0, size)] = value;
    }
  }
}

bool BitcoinExchange::isValidateDate(std::string str) {
  if (str.length() != 10) {
    return false;
  }

  std::string split_line;
  std::istringstream ss(str);
  int y, m, d;
  int idx = 0;

  while (std::getline(ss, split_line, '-')) {
    if (idx == 0) {
      std::istringstream(split_line) >> y;
      if (y < 2009 || y > 2022) {
        return false;
      }
    } else if (idx == 1) {
      std::istringstream(split_line) >> m;
      if (m < 1 || m > 12) {
        return false;
      }
    } else if (idx == 2) {
      std::istringstream(split_line) >> d;
      if (d < 1 || d > 31) {
        return false;
      }
    }
    idx++;
  }
  return true;
}

bool BitcoinExchange::isValidateValue(std::string str) {
  char *ptr = NULL;
  double value = std::strtod(str.c_str(), &ptr);
  if (value == 0.0 && !std::isdigit(str[0])) return false;
  if (*ptr && std::strcmp(ptr, "f")) return false;
  if (value < 0) return false;
  return true;
}

void BitcoinExchange::run(char *file) {
  try {
    checkFile();
    checkInputFile(file);
  } catch (BitcoinExchange::Error &e) {
    return;
  }

  match(file);
}

void BitcoinExchange::match(char *file) {
  std::ifstream configfile(file);

  std::string read;
  getline(configfile, read);
  while (getline(configfile, read)) {
    checkInfo(read);
  }
}

BitcoinExchange::Error::Error(std::string msg) {
  std::cerr << "Error: " << msg << std::endl;
}

const char *BitcoinExchange::Error::what() const throw() {
  return "Error: BitcoinExchange::Error";
}

void BitcoinExchange::printBitcoinDatas() {
  std::map<std::string, float>::iterator it = _bitcoinDatas.begin();
  while (it != _bitcoinDatas.end()) {
    std::cout << it->first << " => " << it->second << '\n';
    it++;
  }
}
void BitcoinExchange::checkInfo(std::string info) {
  std::string date, str;
  std::istringstream formats(info);
  float value;
  int idx = 0;

  while (std::getline(formats, str, ' ')) {
    if (idx == 0) {
      if (checkDate(str) == 0) return;
      date = str;
    }

    if (idx == 1 && str != "|") {
      std::cout << "Error: bad input  => " << info << std::endl;
      return;
    }

    if (idx == 2) {
      if (checkValue(str) == 0) return;
      value = std::strtod(str.c_str(), NULL);
      if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return;
      }
    }
    idx++;
  }

  if (idx != 3) {
    std::cout << "Error: bad input => " << info << std::endl;
    return;
  }

  printBit(date, value);
}

int BitcoinExchange::checkDate(const std::string &dates) {
  std::string date_split;
  std::istringstream ss(dates);
  int year, month, day;
  int idx = 0;

  if (dates.find('-', dates.length() - 1) != std::string::npos) {
    std::cout << "Error: incorrect date formate => " << dates << std::endl;
    return false;
  }
  while (std::getline(ss, date_split, '-')) {
    if (idx == 0) {
      std::istringstream(date_split) >> year;
      if (year < 2009 || year > 2022) {
        std::cout << "Error: invalid year => " << dates << std::endl;
        return false;
      }
    }

    if (idx == 1) {
      std::istringstream(date_split) >> month;
      if (month < 1 || month > 12) {
        std::cout << "Error: invalid month => " << dates << std::endl;
        return false;
      }
    }

    if (idx == 2) {
      std::istringstream(date_split) >> day;
      if (day < 1 || day > 31) {
        std::cout << "Error: bad input => " << dates << std::endl;
        return false;
      }

      if (day == 31 &&
          (month == 4 || month == 6 || month == 9 || month == 11)) {
        std::cout << "Error: incorrect days => " << dates << std::endl;
        return false;
      }

      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        if (day > 29 && month == 2) {
          std::cout << "Error: incorrect days => " << dates << std::endl;
          return false;
        }
      } else if (day > 28 && month == 2) {
        std::cout << "Error: incorrect days => " << dates << std::endl;
        return false;
      }
    }
    idx++;
  }

  if (idx != 3) {
    std::cout << "Error : Wrong format => " << dates << std::endl;
    return false;
  }
  return true;
}

int BitcoinExchange::checkValue(const std::string &str) {
  char *ptr = NULL;
  double value = std::strtod(str.c_str(), &ptr);

  if (str.find('.', 0) == 0 ||
      str.find('.', str.length() - 1) != std::string::npos) {
    std::cout << "Error: not a Number" << std::endl;
    return false;
  }

  if (value == 0.0 && !std::isdigit(str[0])) {
    std::cout << "Error: not a Number" << std::endl;
    return false;
  }

  if (*ptr && std::strcmp(ptr, "f")) {
    std::cout << "Error: not a Number" << std::endl;
    return false;
  }

  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  }

  if (str.length() > 10 || (str.length() == 10 && value > 2147483647)) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}

void BitcoinExchange::printBit(std::string date, float n) {
  std::map<std::string, float>::iterator iter;
  float res;

  res = 0;
  iter = _bitcoinDatas.find(date);
  if (iter != _bitcoinDatas.end())
    res = (iter->second) * n;
  else {
    iter = _bitcoinDatas.lower_bound(date);
    if (iter == _bitcoinDatas.begin()) {
      std::cout << "Error : invalid date" << std::endl;
      return;
    }
    --iter;
    res = (iter->second) * n;
  }

  (n == static_cast<int>(n))
      ? std::cout << date << " => " << static_cast<int>(n) << " = " << res
                  << std::endl
      : std::cout << date << " => " << n << " = " << res << std::endl;
}