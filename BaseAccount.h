#pragma once
class BaseAccount
{
	//Members here:
protected:
	float _acctBalance=0;//Why initialize as zero in class member declaration instead of default constructor or visa versa?
	int _numWithdrawals = 0;

	//Methods here:
public:
	virtual void Withdraw(float amount);// decreases balance by amount. Does NOT “move” the money anywhere, simply reduces the balance and adds 1 to number of withdrawals
	virtual void Deposit(float amount); //increases balance by amount
	float GetBalance() const { return _acctBalance; }; //returns the balance
};

