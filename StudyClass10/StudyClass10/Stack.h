#ifndef _STACK_H
#define _STACK_H

#include "stdafx.h"

struct customer{
	char fullname[35];
	double payment;
};
typedef customer Item;

class Stack{
private:
	static const int MAX = 3;
	Item m_items[MAX];
	int top;
	double add_payment;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
	void show_payment() const;
};
#endif


