#include "BaseAccount.h"
#include <iostream>

void BaseAccount::Withdraw(float amount)// decreases balance by amount. Does NOT “move” the money anywhere, simply reduces the balance and adds 1 to number of withdrawals
{
	if (_acctBalance >= amount && _acctBalance != 0)
	{
		_acctBalance -= amount;//reduce balance by the amount
		_numWithdrawals += 1;//increase _numWithdrawals by 1
	}
	if ((_acctBalance - amount) <= 0)
	{
		_acctBalance = 0;
	}
	if (_acctBalance <= 0)
	{
		std::cout << "You have zero dollars remaining in this account. Please deposit more money to make any more withdrawals.\n";
	}
}
void BaseAccount::Deposit(float amount) //increases balance by amount
{
	_acctBalance += amount;
}