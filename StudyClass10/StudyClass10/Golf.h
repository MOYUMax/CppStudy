#pragma once
#include "stdafx.h"

class Golf{
private:
	static const int LEN = 40;
	char fullname[LEN];
	int handicap;
public:
	Golf();
	Golf(const char * name, int inhand = 0);
	void set(const char * name,int inhand = 0);
	void writehand(int hc);
	void show() const;
};