#pragma once
#include "BaseAccount.h"
class CheckingAccount : public BaseAccount
{
	//Methods here:
public:
	void Withdraw(float amount) override;//override baseaccount version of Withdraw()
};

