#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
  return _nbAccounts;
}
int Account::getTotalAmount(void) {
  return _totalAmount;
}
int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}
int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";"
            << "total:" << _totalAmount << ";"
            << "deposits:" << _totalNbDeposits << ";"
            << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructor
Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created" << std::endl;
}

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "deposit:" << deposit << ";";
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << std::endl;
}

// try to make a withdrawal and return true if it was successful, false otherwise
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";";
  if (_amount < withdrawal) {
    std::cout << "withdrawal:" << "refused" << std::endl;
    return false;
  }
  std::cout << "withdrawal:" << withdrawal << ";";
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

// display status with this format accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << std::endl;
}

// display first timestamp in this format: [20150406_153629]_
void Account::_displayTimestamp(void) {
  static time_t firstTime = time(0);
  time_t        now = firstTime;
  tm*           localTime = localtime(&now);
  char          timestamp[18];
  strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", localTime);
  std::cout << timestamp << " ";
}
