#ifndef _WINE_H
#define _WINE_H

#include "stdafx.h"
#include <valarray>//����������ֵ����ģ��

typedef valarray<int> ArrayInt;//���Ƽ�
template <class T1, class T2>//�����������Ͳ����� Pair ģ�嶨��
class Pair{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const{ return a; }
	T2 second() const{ return b; }
	Pair():a(0),b(0){}
	Pair(const T1 & aval, const T2 & bval) :a(aval), b(bval){}
};
template<class T1,class T2>//ģ��ķ���ʵ��
T1  & Pair<T1, T2>::first(){
	return a;
}
template<class T1,class T2>//ģ��ķ���ʵ��
T2 & Pair<T1, T2>::second(){
	return b;
}
typedef Pair<ArrayInt, ArrayInt> PairArray;//���� Pair<valarray<int>,valarray<int>>�����Ƽ򻯡�

class Wine{
private:
	string label;
	int years;
	PairArray paint;
public:
	Wine();
	Wine(const char * lab, int y, const int yr[], const int bot[]);
	Wine(const char * lab, int y);
	void GetBottles();//�����û�����
	string & Label() const;
	int sum() const;//���ؾ�ƿ���ܺ�
};

#endif