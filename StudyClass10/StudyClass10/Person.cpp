#include "stdafx.h"
#include "Person.h"

Person::Person(const string & ln, const char * fn){
	lname = ln;
	strcpy(fname, fn);
}
void Person::show() const{
	cout << "Person name:" << fname << " " << lname << endl;
	return;
}
void Person::FormalShow()const{
	cout << "Person name:" << lname << " " << fname << endl;
	return;
}