#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit){
    _nbDeposits = initial_deposit;
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
    std::cout << "accounts: " << getNbAccounts() << ";"
        << "total: " << getTotalAmount() << ";"
        << "deposits: " << getNbDeposits() << ";"
        << "withdrawals: " << getNbWithdrawals() << ";" << std::endl;
}

void    Account::displayStatus() const{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "deposits" << this->_nbDeposits << ";"
        << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(){

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
        << "]";
}