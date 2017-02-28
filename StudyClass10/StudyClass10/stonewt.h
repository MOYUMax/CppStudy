#ifndef STONEWT_H_
#define STONEWT_H_

#include "stdafx.h"
class Stonewt{
private:
	static const int LBS_PER_STN = 14;//pounds per stone
	enum Mode{STONE ,POUNDS};//set mode STONE:stone+int_pounds or POUNDS: double pounds
	int stone;
	double pds_left;//fractional pounds
	double pounds;
	Mode m_mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void reset(double lbs = 0.0);
	void reset(int stn, double pds);
	void transion();
	void set_mode_stone();
	void set_mode_pounds();
	Stonewt operator+(const Stonewt & st) const;
	Stonewt operator-(const Stonewt & st) const;
	Stonewt operator*(double n) const;
	friend ostream & operator<<(ostream & os,const Stonewt & st);
	bool operator>(const Stonewt & st) const{
		return pounds > st.pounds ? true : false;
	}
	bool operator<(const Stonewt & st) const{
		return pounds < st.pounds ? true : false;
	}
	bool operator>=(const Stonewt & st) const{
		return pounds >= st.pounds ? true : false;
	}
	bool operator<=(const Stonewt & st) const{
		return pounds <= st.pounds ? true : false;
	}
	bool operator==(const Stonewt & st) const{
		return pounds == st.pounds ? true : false;
	}
	bool operator!=(const Stonewt & st) const{
		return pounds != st.pounds ? true : false;
	}
};
#endif