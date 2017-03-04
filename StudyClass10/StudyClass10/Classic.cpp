#include "stdafx.h"
#include "Classic.h"

Cd::Cd(){
	strcpy(performers, "CD_Performers");
	strcpy(label, "CD_label");
	selections = 0;
	playtime = 0.0;
}
Cd::Cd(char *s1,char *s2,int n,double x){
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd &d){
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
void Cd::Report() const{
	cout << "Cd Report:\nPerformers:\t" << performers << "\nLabel:\t" << label
		<< "\tSelections:\t" << selections << "\tPlaytime:\t" << playtime << endl;
	return;
}
Classic::Classic(){
	Cd();
	strcpy(mp, "Classic_Main_Production");
}
Classic::Classic(char * s, char * s1, char *s2, int n, double x):Cd(s1,s2,n,x){
	strcpy(mp, s);
}
Classic::Classic(const Classic & c){
	*this = c;
}
void Classic::Report() const{
	cout << "Classic Report:\nMain_Productions:\t" << mp << "\n";
	Cd::Report();
}