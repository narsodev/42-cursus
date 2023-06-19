#include <map>
#include <iostream>
#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::complain(std::string level) {
  std::map<std::string, void (Harl::*)(void)> logLevels;

  logLevels.insert(std::pair<std::string, void (Harl::*)(void)>("DEBUG", &Harl::debug));
  logLevels.insert(std::pair<std::string, void (Harl::*)(void)>("INFO", &Harl::info));
  logLevels.insert(std::pair<std::string, void (Harl::*)(void)>("WARNING", &Harl::warning));
  logLevels.insert(std::pair<std::string, void (Harl::*)(void)>("ERROR", &Harl::error));

  std::map<std::string, void (Harl::*)(void)>::const_iterator logLevel = logLevels.find(level);
  if (logLevel == logLevels.end()) {
    std::cerr << "Unknown log level: " << level << std::endl;
    return;
  }

  (this->*(logLevel->second))();
}

void Harl::debug(void) {
  std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- \
ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put \
enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}