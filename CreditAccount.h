#pragma once
#include "BaseAccount.h"
class CreditAccount : public BaseAccount
{
	//Memberss here:
private:
	int _creditUsed=0;

	//Methods here:
	void Withdraw(float amount) override;//override baseaccount version of Withdraw()
};

