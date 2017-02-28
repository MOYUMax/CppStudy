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
		//默认构造函数
		Sales();
		//构造函数
		Sales(const double ar[], int n);
		//设置Sales类对象内容
		void set(const double ar[], int n);
		void show() const;
	};
}