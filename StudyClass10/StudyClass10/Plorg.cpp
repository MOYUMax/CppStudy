#include "stdafx.h"
#include "Plorg.h"

Plorg::Plorg(const char * name, const int pc){
	strncpy(fullname, name,MAX-1);
	ci = pc;
}
void Plorg::set_ci(const int pc){
	ci = pc;
}
void Plorg::show() const{
	cout << "The Plorg fullname:" << fullname << "\t and it's CI = " << ci << endl;
}