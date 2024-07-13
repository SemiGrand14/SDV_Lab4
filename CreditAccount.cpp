#include "CreditAccount.h"
#include <iostream>

void CreditAccount::Withdraw(float amount)
{
	int overdraftFee = 5000; //set overdraft fee
	if (_creditUsed > 40 || (amount + _creditUsed) > 40) //if you are at your credit limit already or this withdrawal will put you over your credit limit...
	{
		BaseAccount::Deposit(amount + overdraftFee);//use deposit here since its a credit account and a higher balance is the amount of debt
		std::cout << "You have gone over the $40 spending limit. This withdrawal and all subsequent withdrawals will incur a \033[31m$5000 fee.\n";
		_creditUsed += amount;//increase credit used
	}
	else
	{
		BaseAccount::Deposit(amount);
		_creditUsed += amount;//increase credit used
	}
}
void CreditAccount::Deposit(float amount)
{
	BaseAccount::Withdraw(amount);//use withdraw here since its a credit account and you pay off the balance of the account.
	_creditUsed -= amount;//decrease used credit
}
