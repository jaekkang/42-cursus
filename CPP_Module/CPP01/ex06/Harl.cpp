#include "Harl.hpp"
void Harl::putDefault(void) {
    std::cout << "[ Probably complaining about insignificantproblems ] "
              << std::endl;
}
void Harl::runDebug(std::string command) {
    if (command != "DEBUG" && this->flag == 0) {
        return;
    }
    this->debug();
    this->flag = 1;
}
void Harl::runInfo(std::string command) {
    if (command != "INFO" && this->flag == 0) {
        return;
    }
    this->info();
    this->flag = 1;
}
void Harl::runWarning(std::string command) {
    if (command != "WARNING" && this->flag == 0) {
        return;
    }
    this->warning();
    this->flag = 1;
}
void Harl::runError(std::string command) {
    if (command != "ERROR" && this->flag == 0) {
        this->putDefault();
        return;
    }
    this->error();
    this->flag = 1;
}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-specialketchup burger. I "
                 "really do!\n"
              << std::endl;
}
void Harl::info(void) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You "
              << "didn’t put enough bacon in my burger! If you did, I wouldn’t "
              << "be asking for more!\n"
              << std::endl;
}
void Harl::warning(void) {
    std::cout
        << "[ WARNING ]\n"
        << "I think I deserve to have some extra bacon for free. I’ve been "
        << "coming for years whereas you started working here since last "
           "month.\n"
        << std::endl;
}
void Harl::error(void) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}
