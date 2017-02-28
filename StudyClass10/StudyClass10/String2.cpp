#include "stdafx.h"
#include "String2.h"

int String::num_strings = 0;

int String::HowMany(){
	return num_strings;
}

String::String(const char *s){
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}
String::String(){
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String &S){
	len = S.len;
	str = new char[len + 1];
	strcpy(str, S.str);
	num_strings++;
}
String::~String(){
	--num_strings;
	delete[] str;
}
//赋值运算符重载
String & String::operator=(const String &st){
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}
String & String::operator=(const char * s){
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
char & String::operator[](int i){
	return str[i];
}
const char & String::operator[](int i)const{
	return str[i];
}
bool String::StringLow(){
	if (str == NULL || len == 0)
		return false;
	for (int i = 0; i < len; i++)
		str[i]=tolower(str[i]);//可以吗？
	return true;
}
bool String::StringUp(){
	if (str == NULL || len == 0)
		return false;
	for (int i = 0; i < len; i++){
		str[i]=toupper(str[i]);
	}		
	return true;
}
int String::search(const char &c){
	if (str == NULL || len == 0)
		return false;
	int countc = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == c)
			countc++;
	}
	return countc;
}
//友元函数的运算符重载
String operator+(const String & st,const String & st2){
	char * temp = new char[st.len + st2.len + 1];
	strcpy(temp, st.str);
	strcat(temp, st2.str);
	String AddString = String(temp);//这样能行吗？
	return AddString;
}
bool operator<(const String & st, const String & st2){
	return (strcmp(st.str, st2.str)<0);
}
bool operator>(const String & st, const String & st2){
	return st2 < st;
}
bool operator==(const String & st, const String & st2){
	return(strcmp(st.str, st2.str) == 0);
}
ostream & operator<<(ostream  &os, const String &st){
	os << st.str;
	return os;
}
istream & operator>>(istream  & is, String & st){
//	char * temp = new char[String::CINLIM + 1];
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;

//	strcpy(st.str, "\0");
//	is.get(st.str, st.len);
	while (is && is.get() != '\n')
		continue;
	return is;
}
