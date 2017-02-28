#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include "stdafx.h"
class complex{
private:
	double real;
	double imaginary;
//	const char im = 'i';
public:
	complex();
	complex(double r, double i);
	~complex();
//	double real_val(){ return real; }
//	double imagin_val(){ return imaginary; }
	void reset(double r, double i){ real = r; imaginary = i; }
	complex operator+(const complex & c);
	complex operator-(const complex & c);
	complex operator*(const complex & c);
	complex operator*(const double & c);
	complex operator~();
	friend ostream & operator<<(ostream & os, const complex & c);
	friend istream & operator>>(istream & is, complex & c);
};
#endif