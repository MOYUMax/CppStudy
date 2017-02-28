#include "stdafx.h"
#include "BankAcount.h"

BankAcount::BankAcount(const string & name, const string & acounum, double ban_val){
	user_name = name;
	user_acount_num = acounum;
	balance = ban_val;
}
void BankAcount::show() const{
	cout << "Uers name: \t" << user_name << endl
		<< "Bank Acount number:" << user_acount_num << endl
		<< "Balance is: \t" << balance << endl;
	return;
}
void BankAcount::deposit(double cash){
	balance += cash;
	cout << "Deposit " << cash << " dollars And now the balance is " << balance << "dollars" << endl;
	return;
}
void BankAcount::withdraw(double cash){
	if (balance < cash)
		cout << "Withdraw failed because lack of Balance.!" << endl;
	else{
		balance -= cash;
		cout << "Withdraw " << cash << "dollars succeed!" << endl
			<< "Acount " << balance << "dollars left!" << endl;
	}
	return;
}
