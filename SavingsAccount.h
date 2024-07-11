#pragma once
#include "BaseAccount.h"
class SavingsAccount : public BaseAccount
{

	//Methods here:
	void Withdraw(float amount) override;//override baseaccount version of Withdraw()
};

