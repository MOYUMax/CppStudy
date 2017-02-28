#ifndef _STOCK_H
#define _STOCK_H

//#include "stdafx.h"
using std::ostream;
using std::istream;

class Stock{
private:
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares*share_val; }
public:
	//construct functions
	Stock();
	Stock(const char * com, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock & topval(const Stock & s) const;
	friend ostream & operator<<(ostream & os,const Stock & s);
};

#endif