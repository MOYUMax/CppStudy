#ifndef _WINE_H
#define _WINE_H

#include "stdafx.h"
#include <valarray>//����������ֵ����ģ��

typedef std::valarray<int> ArrayInt;//���Ƽ�

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
	Pair(){}
	Pair(const T1 & aval, const T2 & bval) :a(aval), b(bval){}

//	Pair & operator=(const Pair<T1, T2> & p);
};
template<class T1,class T2>//ģ��ķ���ʵ��
T1  & Pair<T1, T2>::first(){
	return a;
}
template<class T1,class T2>//ģ��ķ���ʵ��
T2 & Pair<T1, T2>::second(){
	return b;
}
//template<class T1, class T2>
//Pair<T1,T2> & operator=(const Pair<T1,T2> & p)
//{
//	return p;
//}
typedef Pair<ArrayInt, ArrayInt> PairArray;//���� Pair<valarray<int>,valarray<int>>�����Ƽ򻯡�

class Wine{
private:
	string label;
	int years;
	PairArray  paint;
public:
	Wine();
	Wine(const char * lab, int y, const int yr[], const int bot[]);
	Wine(const char * lab, int y);
	void GetBottles();//�����û�����
	const string & Label() const;
	int sum() const;//���ؾ�ƿ���ܺ�
	void Show() const;//��ʾWine������Ϣ
	int input(int a);
};

class Wine_Private : private std::string, private PairArray
{
public:
	Wine_Private();
	Wine_Private(const char * lab, int y, const int yr[], const int bot[]);
	Wine_Private(const char * lab, int y);
	void GetBottles();
	const string & Label() const;
	const PairArray & WinePPA()const;
	int sum();
	void Show();
	int input(int a);
};

#endif