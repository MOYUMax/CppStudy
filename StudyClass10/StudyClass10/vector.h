#ifndef VECTOR_H_
#define VECTOR_H_

#include "stdafx.h"

namespace VECTOR{
	class Vector{
	public:
		//向量两种表示方法：RECT：（x,y)坐标；POL：长度+角度
		enum Mode{RECT,POL};
	private:
		double x;
		double y;
		//长度
//		double mag;
		//角度
//		double ang;
		//模式 = 向量两种表示方法：RECT：（x,y)坐标；POL：长度+角度
		Mode mode;
//		void set_mag();
//		void set_ang();
//		void set_x();
//		void set_y();
		void set_x(double n1, double n2, Mode form = POL);
		void set_y(double n1, double n2, Mode form = POL);
	public:
		Vector();
		//带参初始化，默认RECT方法，n1 = x,n2 = y;POL方法：n1 = mag,n2 = ang
		Vector(double n1, double n2, Mode form = RECT);
		//重置向量，默认RECT方法，n1 = x,n2 = y;POL方法：n1 = mag,n2 = ang
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double Xval() const{ return x; }
		double Yval() const{ return y; }
//		double magval() const{ return mag; }
//		double angval() const{ return ang; }'
		double magval() const;
		double angval() const;
		//设置mode = POL ，极坐标方法
		void polar_mode();
		//设置mode = RECT，点坐标方法 
		void rect_mode();
		//运算符重载：加+
		Vector operator+(const Vector & b) const;
		//运算符重载：减-
		Vector operator-(const Vector & b) const;
		//运算符重载：取负-
		Vector operator-() const;
		//运算符重载：乘浮点倍数*
		Vector operator*(double n) const;
		//友元函数：运算符重载：乘浮点倍数*
		friend Vector operator*(double n, const Vector & a);
		//友元函数：运算符重载：输出流<<
		friend ostream& operator<<(ostream & os, const Vector & v);
	};
}
#endif