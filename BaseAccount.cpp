#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)// decreases balance by amount. Does NOT “move” the money anywhere, simply reduces the balance and adds 1 to number of withdrawals
{
	if (_acctBalance >= amount)
	{
		_acctBalance -= amount;
		_numWithdrawals += 1;
	}
}
void BaseAccount::Deposit(float amount) //increases balance by amount
{
	_acctBalance = +amount;
}