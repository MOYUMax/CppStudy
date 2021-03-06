#ifndef _WINE_H
#define _WINE_H

#include "stdafx.h"
#include <valarray>//处理数组数值的类模板

typedef std::valarray<int> ArrayInt;//名称简化

template <class T1, class T2>//包含两个类型参数的 Pair 模板定义
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
template<class T1,class T2>//模板的方法实现
T1  & Pair<T1, T2>::first(){
	return a;
}
template<class T1,class T2>//模板的方法实现
T2 & Pair<T1, T2>::second(){
	return b;
}
//template<class T1, class T2>
//Pair<T1,T2> & operator=(const Pair<T1,T2> & p)
//{
//	return p;
//}
typedef Pair<ArrayInt, ArrayInt> PairArray;//这是 Pair<valarray<int>,valarray<int>>的名称简化。

class Wine{
private:
	string label;
	int years;
	PairArray  paint;
public:
	Wine();
	Wine(const char * lab, int y, const int yr[], const int bot[]);
	Wine(const char * lab, int y);
	void GetBottles();//接受用户输入
	const string & Label() const;
	int sum() const;//返回酒瓶数总和
	void Show() const;//显示Wine对象信息
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