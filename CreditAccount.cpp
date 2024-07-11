#include "CreditAccount.h"
#include <iostream>

void CreditAccount::Withdraw(float amount)
{
	int overdraftFee = 5000;
	if (_creditUsed > 40)
	{
		BaseAccount::Withdraw(amount + overdraftFee);
		std::cout << "You have gone over the $40 spending limit. This withdrawal and all subsequent withdrawals will incur a $5000 fee.";
	}
	else
	{
		BaseAccount::Withdraw(amount);
	}
}
