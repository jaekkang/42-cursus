#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
  BitcoinExchange b;
  if (ac != 2) {
    BitcoinExchange::Error("Usage: ./btc [file]");
    exit(0);
  }

  b.run(av[1]);
  return (0);
}