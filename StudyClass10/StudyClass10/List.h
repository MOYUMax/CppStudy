#ifndef _LIST_H_
#define _LIST_H_

#include "stdafx.h"
typedef int Type;

class List{
private:
	static const int MAX = 6;
	Type m_items[MAX];
	int m_pi;
public:
	List();
	bool add(const Type & item);
	bool isempty() const;
	bool isfull() const;
	void visit(void(*pf)(Type &));
};
#endif