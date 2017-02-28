#include "stdafx.h"
#include "complex0.h"

complex::complex(){
	real = 0.0;
	imaginary = 0.0;
}
complex::complex(double r, double i){
	real = r;
	imaginary = i;
}
complex::~complex(){
//	cout <<this->real<<" + "<<this->imaginary<<"i ±»Ïú»ÙÁË" << endl;
}
complex complex::operator+(const complex & c){
	return complex((real + c.real), (imaginary + c.imaginary));
}
complex complex::operator-(const complex & c){
	return complex((real - c.real), (imaginary - c.imaginary));
}
complex complex::operator*(const complex & c){
	double cr = c.real;
	double ci = c.imaginary;
	return complex((real*cr-imaginary*ci), (real*ci+imaginary*cr));
}
complex complex::operator*(const double & c){
	return complex(real * c , imaginary * c);
}
complex complex::operator~(){
	return complex(real , -imaginary);
}
ostream & operator<<(ostream & os, const complex & c){
	os << "(" << c.real << "," << c.imaginary << "i)";
	return os;
}
istream & operator>>(istream & is, complex & c){
	is >> c.real >> c.imaginary;
	return is;
}