#include "stdafx.h"
#include "Stack12.h"

//Stack12::Stack12(){
//	pitems = new ItemS[5];
//	size = 5;
//	top = 0;
//}
Stack12::Stack12(int n){
	pitems = new ItemS[n];
	size = n;
	top = 0;
}
Stack12::Stack12(const Stack12 &st){
	size = st.size;
	pitems = new ItemS[size];
	for (int i = 0; i < st.top; i++)
		pitems[i] = st.pitems[i];
	top = st.top;
}
Stack12::~Stack12(){
	delete[] pitems;
	size = 0;
	top = INT_MAX;
}
bool Stack12::isempty() const{
	return top == 0;
}
bool Stack12::isfull() const{
	return top >= size;
}
bool Stack12::push(const ItemS & item){
	if (this->isfull()){
		cout << "The Stack is full ,can`t Push anymore;\n";
		return false;
	}
	else{
		pitems[top++] = item;
		cout << "Push " << top - 1 << " Item = " << item << "Succeed!" << endl;//²âÊÔÓÃ
		return true;
	}
}
bool Stack12::pop(ItemS & item){
	if (this->isempty()){
		cout << "The Stack is empty ,can`t Pop anymore:\n";
		return false;
	}
	else{
		item = pitems[--top];
		cout << "Pop " << top << " Item = " << item << "Succeed!" << endl;//²âÊÔÓÃ
		return true;
	}
}
Stack12 & Stack12::operator=(const Stack12 & st){
	if (this == &st)
		return *this;
	/*for (int i = 0; i < st.top; i++)
		this->push(st.pitems[i]);*/
	delete [] pitems;
	pitems = new ItemS[st.size];
	top = st.top;
	for (int i = 0; i < top; i++)
		pitems[i] = st.pitems[i];

	return *this;
} 