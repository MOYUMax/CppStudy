#ifndef _STACK12_H
#define _STACK12_H

typedef unsigned long ItemS;
class Stack12{
private:
	enum{ MAX = 10 };
	ItemS * pitems;
	int size;
	int top;
public:
//	Stack12();
	Stack12(int n = MAX);
	Stack12(const Stack12 & st);
	~Stack12();
	bool isempty() const;
	bool isfull() const;
	bool push(const ItemS & item);
	bool pop(ItemS & item);
	Stack12 & operator=(const Stack12 & st );
};

#endif