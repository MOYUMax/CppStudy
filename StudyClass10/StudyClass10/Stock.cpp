#include "stdafx.h"
#include "Stock.h"
//construct functions
Stock::Stock(){
	company = new char[10];
	strcpy(company, "No name!");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char * com, long n, double pr){
	company = new char[strlen(com)+1];
	strcpy(company, com);
	shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock(){
//	cout << "Destroy the stock of " << company << " with the shares = " << shares << "\nIt`s total = " << total_val << ",Each share has	Price = " << share_val << endl;
	delete [] company;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
//public function;
void Stock::buy(long num, double price){
	if (num < 0){
		cout << "Number of shares purchased can't be negative!" << endl;
		cout << "Transaction is aborted." << endl;
	}
	else{
		shares += num;
		share_val = price;
		set_tot();
	}
	return;
}
void Stock::sell(long num, double price){
	if (num < 0){
		cout << "Number of shares purchased can't be negative!" << endl;
		cout << "Transaction is aborted." << endl;
	}
	else if(num>shares){
		cout << "You can't sell more than you have!\nTransaction is aborted." << endl; 
	}
	else{
		shares -= num;
		share_val = price;
		set_tot();
	}
	return;
}
void Stock::update(double price){
	share_val = price;
	set_tot();
}
const Stock & Stock::topval(const Stock & s)const{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
ostream & operator<<(ostream & os, const Stock &s){
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);
	os <<"Company = "<< s.company << "Shares = " << s.shares << "\nShares Price = $" << s.share_val ;
	
	cout.precision(2);
	os << " Total Worth = $" << s.total_val << endl;
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

	return os;
}