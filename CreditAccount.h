#pragma once
#include "BaseAccount.h"
class CreditAccount : public BaseAccount
{
	//Memberss here:
private:
	int _creditUsed = 0;

	//Methods here:
public:
	void Withdraw(float amount) override;//override baseaccount version of Withdraw()
	void Deposit(float amount) override; //override baseaccount version of Deposit() in order to reduce the account balance when the user puts money in
};

