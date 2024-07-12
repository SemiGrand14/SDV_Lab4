#include "CheckingAccount.h"
#include <iostream>

void CheckingAccount::Withdraw(float amount)
{
	int withdrawalFee = 5;//initialize the withdrawal fee
	BaseAccount::Withdraw(amount);//call the base withdraw to adjust account balance
	if (_numWithdrawals > 10)//if more than 10 withdrawals have been made...
	{
		_acctBalance -= withdrawalFee;//take the fee from the account balance
		std::cout << "\nYou have exceeded the maximum 10 free withdrawals. This and each subsequent withdrawal will incur a $5 fee.\n";
	}
}
