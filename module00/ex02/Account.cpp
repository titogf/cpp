#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";created" << std::endl;
}

Account::Account(void){
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";created" << std::endl;
}

Account::~Account(void){
    _nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";closed" << std::endl;
}

int Account::getNbAccounts(void){
    return (_nbAccounts);
}

int Account::getTotalAmount(void){
    return (_totalAmount);
}

int Account::getNbDeposits(void){
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void){
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

void    Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "deposits" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void){

    time_t now = time(0);
    tm *lt = localtime(&now);

    std::cout << "["
        << lt->tm_year 
        << std::setw(2) << std::setfill('0') << lt->tm_mon 
        << std::setw(2) << std::setfill('0') << lt->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << lt->tm_hour 
        << std::setw(2) << std::setfill('0') << lt->tm_min
        << std::setw(2) << std::setfill('0') << lt->tm_sec
        << "] ";
}

void    Account::makeDeposit(int deposit){
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
        << ";p_amount:" << _amount - deposit
        << ";deposit:" << deposit 
        << ";amount:" << _amount 
        << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal){
    if (_amount < withdrawal){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
        << ";p_amount:" << _amount + withdrawal
        << ";withdrawal:" << withdrawal 
        << ";amount:" << _amount 
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const{
    return (_amount);
}