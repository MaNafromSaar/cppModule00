/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:18:02 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/12 18:34:13 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::setw;
using std::string;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::~Account(void) {
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount < withdrawal) {
		cout << ";withdrawal:refused" << endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << endl;
	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << endl;
}

void Account::_displayTimestamp(void) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout << std::put_time(ltm, "[%Y%m%d_%H%M%S]");
}

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
	cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << endl;
}

//first test main
/*int main() {
	Account account1(100);
	Account account2(200);
	account1.makeDeposit(500);
	account1.makeWithdrawal(100);
	account1.makeWithdrawal(1000);
	account1.displayStatus();
	account2.displayStatus();
	Account::displayAccountsInfos();
	return 0;
}*/
