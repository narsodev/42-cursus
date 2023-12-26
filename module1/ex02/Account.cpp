#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit) {
  this->_amount = initial_deposit;
  Account::_totalAmount += initial_deposit;

  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  this->_accountIndex = Account::_nbAccounts;
  Account::_nbAccounts++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

Account::~Account () {
  Account::_totalAmount -= this->_amount;
  Account::_nbAccounts--;
  Account::_nbDeposits -= this->_nbDeposits;
  Account::_nbWithdrawals -= this->_nbWithdrawals;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp(void) {
  std::ostringstream oss;
  std::time_t t = std::time(NULL);
  std::tm *tm = std::localtime(&t);
  oss << "[" << std::setw(4) << std::setfill('0') << (tm->tm_year+1900)
        << std::setw(2) << std::setfill('0') << (tm->tm_mon+1)
        << std::setw(2) << std::setfill('0') << tm->tm_mday
        << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour
        << std::setw(2) << std::setfill('0') << tm->tm_min
        << std::setw(2) << std::setfill('0') << tm->tm_sec << "]";
  std::cout << oss.str() << " ";
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ";";
  std::cout << "total:" << Account::_totalAmount << ";";
  std::cout << "deposits:" << Account::_totalNbDeposits << ";";
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount - deposit << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "withdrawal:";

  if (this->_amount < withdrawal) {
    std::cout << "refused" << std::endl;
    return false;
  }

  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;

  std::cout << withdrawal << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

  return true;
}

int Account::checkAmount(void) const {
  return this->_amount;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
