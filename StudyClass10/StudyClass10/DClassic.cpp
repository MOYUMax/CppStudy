#include "stdafx.h"
#include "DClassic.h"

DCd::DCd():selections(0),playtime(0.0){
	performers = new char[MAX];
	label = new char[MAX];
	strcpy(performers, "DCd_Performers");
	strcpy(label, "Dcd_Lable");	
}
DCd::DCd(char * s1, char * s2, int n, double x):selections(n),playtime(x){
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	/*selections = n;
	playtime = x;*/
}
DCd::DCd(const DCd & dcd){
	performers = new char[strlen(dcd.performers) + 1];
	strcpy(performers, dcd.performers);
	label = new char[strlen(dcd.label) + 1];
	strcpy(label, dcd.label);
	selections = dcd.selections;
	playtime = dcd.playtime;
}
//bool DCd::set_performer(char * per){
//	delete[] performers;
//	performers = new char[strlen(per) + 1];
//	if (performers == nullptr)
//		return false;
//	strcpy(performers, per);
//	return true;
//}
//bool DCd::set_label(char * lab){
//	delete[] label;
//	label = new char[strlen(lab) + 1];
//	if (label == nullptr)
//		return false;
//	strcpy(label, lab);
//	return true;
//}
DCd::~DCd(){
	delete[] performers;
	delete[] label;
}
void DCd::Report()const{
	cout << "Cd Report:\nPerformers:\t" << performers << "\nLabel:\t" << label;
	cout << "Selections: " << selections << " Playtime:" << playtime << endl;
	return;
}
DCd & DCd::operator=(const DCd & dcd){
	if (this == &dcd)
		return *this;
	delete[] performers;
	performers = new char[strlen(dcd.performers) + 1];
	strcpy(performers, dcd.performers);
	delete[] label;
	label = new char[strlen(dcd.label) + 1];
	strcpy(label, dcd.label);
	selections = dcd.selections;
	playtime = dcd.playtime;
	return *this;
}
DClassic::DClassic() :DCd(){
	mp = new char[MAX];
	strcpy(mp, "DClassic_Main_Production");
}
DClassic::DClassic(char * s, char * s1, char * s2, int n, double x)
	: DCd(s1,s2,n,x)
{
	mp = new char[strlen(s) + 1];
	strcpy(mp, s);
}
DClassic::DClassic(const DClassic & dcic):DCd(dcic){
//	DClassic(dcic.get_mp(),dcic.get_performer(), dcic.get_label(), dcic.get_selections(), dcic.get_playtime());
	mp = new char[strlen(dcic.mp) + 1];
	strcpy(mp, dcic.mp);
}
DClassic::~DClassic(){
	delete[] mp;
//	DCd::~DCd();//这里需要显示调用基类的析构函数吗？
}
void DClassic::Report() const{
	cout << "DClassic Report:  mp=" << mp << endl;
	DCd::Report();
}
DClassic & DClassic::operator=(const DClassic & dcic){
	if (this == &dcic)
		return *this;
	delete[] mp;
	mp = new char[strlen(dcic.mp) + 1];
	strcpy(mp, dcic.mp);
	/*this->set_performer(dcic.get_performer());
	this->set_label(dcic.get_label());
	this->set_selections(dcic.get_selections());
	this->set_playtime(dcic.get_playtime());*/
	DCd::operator=(dcic);//显示调用基类的赋值运算符 与上述代码等价
	return *this;
}