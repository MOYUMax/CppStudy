#include "stdafx.h"
#include "List.h"

List::List(){
	m_pi = 0;
}
bool List::isempty() const{
	return m_pi == 0;
}
bool List::isfull() const{
	return m_pi == MAX;
}
bool List::add(const Type &item){
	if (isfull()){
		cout << "Add ERROR!The List is full!" << endl;
		return false;
	}
	else{
		m_items[m_pi++] = item;
		return true;
	}
}
void List::visit(void(*pf)(Type &)){
	if (isempty())
		return;
	for (int i = 0; i < m_pi&&i < MAX; i++){
		(*pf)(m_items[i]);
	}
	return;
}