#pragma once
//#include "stdafx.h"

class BankAcount{
	
private:
	string user_name;
	string user_acount_num;
	double balance;
public:
	BankAcount(){};
	BankAcount(const string & name, const string & acounum, double ban_val = 0);
	void show() const;
	void deposit(double cash);
	void withdraw(double cash);
};