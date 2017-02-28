#include "stdafx.h"
#include "Stack.h"

Stack::Stack(){
	top = 0;
	add_payment = 0;
}
bool Stack::isempty() const{
	return top == 0;
}
bool Stack::isfull() const{
	if (top < MAX)
		return false;
	else
		return true;
}
bool Stack::push(const Item &item){
	if (this->isfull()){
		cout << "PUSH ERROR! The stack is full!" << endl;
		return false;
	}
	else{
		cout << "Push a item:" << item.fullname << " and " << item.payment << "into the stack!" << endl;
		m_items[top++] = item;
	}
	return true;
}
bool Stack::pop(Item & item){
	if (this->isempty()){
		cout << "POP ERROR! The stack is empty!" << endl;
		return false;
	}
	else{
		item = m_items[--top];
		add_payment += item.payment;
		cout << "Pop a item:" << item.fullname << " and payment = " << item.payment << endl;
		cout << "Added item payment to all = " << add_payment << endl;
	}
	return true;
}
void Stack::show_payment() const{
	cout << "The Added Payment = " << add_payment << endl;
	return;
}