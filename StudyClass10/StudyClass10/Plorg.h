#ifndef _PLORG_H_
#define _PLORG_H_

#include "stdafx.h"
class Plorg{
private:
	static const int MAX = 20;
	char fullname[MAX];
	int ci;
public:
	Plorg(const char * name = "Plorga", const int pc = 50);
	void set_ci(const int pc);
	void show() const;
};
#endif