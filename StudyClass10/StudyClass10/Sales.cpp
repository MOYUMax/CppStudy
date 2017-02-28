#include "stdafx.h"
#include "Sales.h"
using namespace SALES;

Sales::Sales(){
	for (int i = 0; i < QUARTERS; i++)
		sales[i] = 0;
	average = 0;
	max = 0;
	min = 0;
}
Sales::Sales(const double ar[], int n){
	int i = 0;
	average = 0;
	min = max = ar[0];
	while (i < n && i < QUARTERS){
		sales[i] = ar[i];
		if (sales[i] > max)
			max = sales[i];
		if (sales[i] < min)
			min = sales[i];
		average += sales[i];
		i++;
	}
	average /= i;
}
void Sales::set(const double ar[], int n){
	*this = Sales(ar, n);
	return;
}
void Sales::show() const{
	for (int i = 0; i < QUARTERS; i++)
		cout << "\tSales[" << i << "] = " << sales[i];
	cout << "\naverage = " << average << "\tmax = " << max
		<< "\tmin = " << min << endl;
	return;
}