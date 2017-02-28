#ifndef _STRING2_H
#define _STRING2_H
#include <iostream>
using std::istream;
using std::ostream;

class String{
private:
	char *str;
	int len;
	static int num_strings;//number of objects
	static const int CINLIM = 80;//cin input limit
public:
	//构造函数，析构函数，内联函数
	String(const char *s);
	String();
	String(const String &S);
	~String();
	int length() const{ return len; }
	//赋值操作符重载函数，中括号对【】操作符重载函数
	String & operator=(const String &S);
	String & operator=(const char * s);
	char & operator[](int i);
	const char & operator[](int i)const;
	bool StringLow();
	bool StringUp();
	int search(const char & c);
	//友元函数，操作符重载函数
	friend String operator+(const String &st,const String &st2);
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream  &os, const String &st);
	friend istream & operator>>(istream  &is, String &st);
	//静态成员函数
	static int HowMany();
};

#endif