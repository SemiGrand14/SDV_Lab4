#pragma once
class BaseAccount
{
	//Members here:
protected:
	float _acctBalance = 0;//initialize to zero
	int _numWithdrawals = 0; //initialize to zero

	//Methods here:
public:
	virtual void Withdraw(float amount);// decreases balance by amount
	virtual void Deposit(float amount); //increases balance by amount
	float GetBalance() const { return _acctBalance; }; //returns the balance
};

