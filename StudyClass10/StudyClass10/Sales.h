#pragma once
#include "stdafx.h"

namespace SALES
{
	class Sales{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		//Ĭ�Ϲ��캯��
		Sales();
		//���캯��
		Sales(const double ar[], int n);
		//����Sales���������
		void set(const double ar[], int n);
		void show() const;
	};
}