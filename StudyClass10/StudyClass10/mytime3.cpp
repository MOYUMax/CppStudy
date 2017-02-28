#include "stdafx.h"
#include "mytime3.h"

Time::Time(){
	hours = 0;
	minutes = 0;
}
Time::Time(int h, int m){
	hours = h;
	minutes = m;
}
void Time::AddMin(int m){
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h){
	hours += h;
}
void Time::Reset(int h, int m){
	hours = h;
	minutes = m;
}
Time operator+(const Time &t1, const Time &t2){
	Time mytime = Time();
	mytime.minutes = t1.minutes + t2.minutes;
	mytime.hours =t1.hours+t2.hours+ int(mytime.minutes / 60);
	mytime.minutes %= 60;
	return mytime;
}
Time operator-(const Time &t1, const Time &t2){
	Time mytime = Time();
	int tot1, tot2;
	tot1 = t1.minutes + t1.hours * 60;
	tot2 = t2.minutes + t2.hours * 60;
	mytime.minutes = (tot1 - tot2) % 60;
	mytime.hours = (tot1 - tot2) / 60;
	return mytime;
}
Time operator*(const Time &t1, double n){
	Time mytime = Time();
	long tot_minutes = long(t1.hours*n * 60 + t1.minutes*n);
	mytime.hours = tot_minutes / 60;
	mytime.minutes = tot_minutes % 60;
	return mytime;
}
Time operator*(double n, const Time & t1){
	return t1*n;
}
ostream & operator<<(ostream &os, const Time &t){
	os << t.hours << " hours " << t.minutes << " minutes";
	return os;
}
