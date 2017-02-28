#ifndef VECTOR_H_
#define VECTOR_H_

#include "stdafx.h"

namespace VECTOR{
	class Vector{
	public:
		//�������ֱ�ʾ������RECT����x,y)���ꣻPOL������+�Ƕ�
		enum Mode{RECT,POL};
	private:
		double x;
		double y;
		//����
//		double mag;
		//�Ƕ�
//		double ang;
		//ģʽ = �������ֱ�ʾ������RECT����x,y)���ꣻPOL������+�Ƕ�
		Mode mode;
//		void set_mag();
//		void set_ang();
//		void set_x();
//		void set_y();
		void set_x(double n1, double n2, Mode form = POL);
		void set_y(double n1, double n2, Mode form = POL);
	public:
		Vector();
		//���γ�ʼ����Ĭ��RECT������n1 = x,n2 = y;POL������n1 = mag,n2 = ang
		Vector(double n1, double n2, Mode form = RECT);
		//����������Ĭ��RECT������n1 = x,n2 = y;POL������n1 = mag,n2 = ang
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double Xval() const{ return x; }
		double Yval() const{ return y; }
//		double magval() const{ return mag; }
//		double angval() const{ return ang; }'
		double magval() const;
		double angval() const;
		//����mode = POL �������귽��
		void polar_mode();
		//����mode = RECT�������귽�� 
		void rect_mode();
		//��������أ���+
		Vector operator+(const Vector & b) const;
		//��������أ���-
		Vector operator-(const Vector & b) const;
		//��������أ�ȡ��-
		Vector operator-() const;
		//��������أ��˸��㱶��*
		Vector operator*(double n) const;
		//��Ԫ��������������أ��˸��㱶��*
		friend Vector operator*(double n, const Vector & a);
		//��Ԫ��������������أ������<<
		friend ostream& operator<<(ostream & os, const Vector & v);
	};
}
#endif