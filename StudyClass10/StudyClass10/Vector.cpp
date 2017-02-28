#include "stdafx.h"
#include "vector.h"
namespace VECTOR{
	
	//度与弧度的比率。tan45度 = 1，所以45度/atan(1.0)就是度/弧度~=57.2957795130823
	const double Rad_to_deg = 45.0 / atan(1.0);
	
	Vector::Vector(){
	//	x = y = mag = ang = 0.0;
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form){
		mode = form;
		if (form == RECT){
			x = n1;
			y = n2;
//			set_mag();
//			set_ang();
		}
		else if (form == POL){
	//		mag = n1;
	//		ang = n2;
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else{
			cout << "Mode模式设置错误，向量初始化设置为零。";
	//		x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = RECT;
		}
	}
	double Vector::magval() const{
		return sqrt(x*x + y*y);
	}
	double Vector::angval() const{
		if (x == 0.0&&y == 0.0)
			return 0.0;
		else
			return atan2(y, x);
	}
	/*
	void Vector::set_mag(){
		mag = sqrt(x*x + y*y);
	}
	
	void Vector::set_ang(){
		if (x == 0.0&&y == 0.0){
			ang = 0.0;
		}
		else{
			ang = atan2(y, x);
		}
	}*/
	
	void Vector::set_x(double n1,double n2,Mode form){
		x = n1*cos(n2);
	}
	void Vector::set_y(double n1,double n2,Mode form){
		y = n1*sin(n2);
	}
	void Vector::reset(double n1, double n2, Mode form){
		mode = form;
		if (form == RECT){
			x = n1;
			y = n2;
//			set_mag();
//			set_ang();
		}
		else if (form == POL){
			set_x(n1,n2);
			set_y(n1,n2);
		}
		else{
			cout << "Mode模式设置错误，向量reset设置为零。";
	//		x = y = mag = ang = 0.0;
			x = y = 0.0;
			mode = RECT;
		}
		return;
	}
	Vector::~Vector(){
//		cout << "向量(" << x << "," << y << ")销毁" << endl;
	}
	void Vector::polar_mode(){
		mode = POL;
	}
	void Vector::rect_mode(){
		mode = RECT;
	}
	Vector Vector::operator+(const Vector &b) const{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector &b) const{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const{
		return Vector(n*x, n*y);
	}
	Vector operator*(double n, const Vector & a){
		return a * n;
	}
	ostream & operator<<(ostream &os, const Vector & v){
		if (v.mode == Vector::RECT){
			os << "(x,y) = (" << v.x << "," << v.y << ")" ;
		}
		else if (v.mode == Vector::POL){
			double m = v.magval(); 
			double a = v.angval();
			os << "(m,a) = (" << m << "," << a*Rad_to_deg << ")";
		}
		else
			os << "向量的mode是非法的，无法输出！" << endl;
		return os;
	}
}
