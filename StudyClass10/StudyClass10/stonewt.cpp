#include "stdafx.h"
#include "stonewt.h"

Stonewt::Stonewt(){
	stone = 0;
	pds_left = 0.0;
	pounds = 0.0;
	m_mode = POUNDS;
}
Stonewt::Stonewt(double lbs){
	stone = int(lbs) / LBS_PER_STN;
	pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
	pounds = lbs;
	m_mode = POUNDS;
}
Stonewt::Stonewt(int stn, double lbs){
	stone = stn;
	pds_left = lbs;
	pounds = stn*LBS_PER_STN + lbs;
	m_mode = STONE;
}
Stonewt::~Stonewt(){
//	cout << "Stonewt " << pounds << "is dead!" << endl;
}
void Stonewt::transion(){
	if (POUNDS == m_mode){
		stone = int(pounds) / LBS_PER_STN;
		pds_left = int(pounds) % LBS_PER_STN + pounds - int(pounds);
	//	m_mode = STONE;
	}
	else if (STONE == m_mode){
		pounds = stone*LBS_PER_STN + pds_left;
	//	m_mode = POUNDS;
	}
	else
		cout << "Transion ERROR!" << endl;
}
void Stonewt::set_mode_stone(){
	this->transion();
	m_mode = STONE;
}
void Stonewt::set_mode_pounds(){
	this->transion();
	m_mode = POUNDS;
}
void Stonewt::reset(double lbs){
	pounds = lbs;
	m_mode = POUNDS;
	this->transion();
}
void Stonewt::reset(int stn, double pds){
	stone = stn;
	pds_left = pds;
	m_mode = STONE;
	this->transion();
}
Stonewt Stonewt::operator+(const Stonewt & st) const{
	Stonewt result = Stonewt();
	result.pounds = pounds + st.pounds;
	result.transion();
	return result;
}
Stonewt Stonewt::operator-(const Stonewt & st) const{
	Stonewt result = Stonewt();
	result.pounds = pounds - st.pounds;
	result.transion();
	return result;
}
Stonewt Stonewt::operator*(double n) const{
	Stonewt result = Stonewt();
	result.pounds = this->pounds * n;
	result.transion();
	return result;
}
ostream & operator<<(ostream & os, const Stonewt &st){
	if (st.m_mode == Stonewt::POUNDS){
		os << st.pounds << " Pounds";
	}
	else if (st.m_mode == Stonewt::STONE){
		os << st.stone << " Stone " << st.pds_left << " Pounds";
	}
	else
		os << "Output Stonewt is ERROR!";
	return os;
}
