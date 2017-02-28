#include "stdafx.h"
#include "Move.h"

Move::Move(double a, double b){
	x = a;
	y = b;
}
void Move::show() const{
	cout << "The current x = " << x << "\tand y = " << y << endl;
	return;
}
Move Move::add(const Move &m) const{
	double a, b;
	a = this->x + m.x;
	b = y + m.y;
	return Move(a, b);
}
void Move::reset(double a, double b){
	x = a;
	y = b;
	return;
}