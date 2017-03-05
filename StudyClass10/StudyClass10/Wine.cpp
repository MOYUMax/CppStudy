#include "stdafx.h"
#include "Wine.h"

Wine::Wine(){
	label = "Default_Label";
	years = 5;
	paint = PairArray(ArrayInt(years), ArrayInt(years));
}
Wine::Wine(const char * lab,int y,const int yt[],const int bot[]):label(lab),years(y){
	ArrayInt yarray = ArrayInt(yt,y);
	ArrayInt barray = ArrayInt(bot, y);
	paint = PairArray(yarray, barray);
}
Wine::Wine(const char * lab, int y):label(lab),years(y),paint(){

}
void Wine::GetBottles(){
	cout << "The Wine " << label <<" Get Bottles!" <<endl;
	
	 for (int i = 0; i < years; i++){
		cout << "Please input the year and the bottles:";
		cin >> paint.first()[i] >> paint.second()[i];
	}
	cout << "End of the Get Bottles ! Thank you!\n";
	return;
}
const string & Wine::Label() const{
	return label;
}
int  Wine::sum() const{
	int sum = 0;
	sum = paint.second().sum();
	return sum;
}
void Wine::Show() const{
	cout << "The Wine " << label << " has " << years << " years differents!\n"
		<< "\tYears\tBottles\n";
	for (int i = 0; i < years; i++)
		cout << "\t" << paint.first()[i] << "\t" << paint.second()[i] << endl;
	return;
}