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
	//���캯����������������������
	String(const char *s);
	String();
	String(const String &S);
	~String();
	int length() const{ return len; }
	//��ֵ���������غ����������Ŷԡ������������غ���
	String & operator=(const String &S);
	String & operator=(const char * s);
	char & operator[](int i);
	const char & operator[](int i)const;
	bool StringLow();
	bool StringUp();
	int search(const char & c);
	//��Ԫ���������������غ���
	friend String operator+(const String &st,const String &st2);
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream  &os, const String &st);
	friend istream & operator>>(istream  &is, String &st);
	//��̬��Ա����
	static int HowMany();
};

#endif