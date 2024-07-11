#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::Withdraw(float amount)
{
	if (_numWithdrawals >= 3)//if the user is at or has gone over the max 3 withdrawals...
	{
		std::cout << "You have hit or exceeded the limit of 3 withdrawals for this account. No more withdrawals can be made at this time.";
	}
	else//if not, continue with the withdrawal
	{
		BaseAccount::Withdraw(amount);
	}
}