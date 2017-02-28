#include "stdafx.h"
#include "Golf.h"

Golf::Golf(){
	fullname[0] = '\0';
	handicap = 0;
	cout << "Golf默认构造函数" << endl;
};
Golf::Golf(const char * name, int inhand){
	strcpy(fullname, name);
	handicap = inhand;
}
void Golf::set(const char * name, int inhand){
	*this = Golf(name, inhand);
	return;
}
void Golf::writehand(int inhand){
	handicap = inhand;
	return;
}
void Golf::show() const{
	cout << "Golf name :" << fullname << "\tIt has " << handicap << " handicap Level.\n";
	return;
}