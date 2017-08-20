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

Wine_Private::Wine_Private() :string("Default label")
{
	//default Construction
}

Wine_Private::Wine_Private(const char * label, int y, const int yr[], const int bot[]) : string(label), PairArray(ArrayInt(yr, y), ArrayInt(bot,y))
{

}

Wine_Private::Wine_Private(const char * label, int y) :string(label),  PairArray(ArrayInt(y),ArrayInt(y))
{

}

const string & Wine_Private::Label() const
{
	return (const string &) *this;
}

const PairArray & Wine_Private::WinePPA() const
{
	return (PairArray &) *this;
}

void Wine_Private::GetBottles()
{
	cout << "The Wine " << Wine_Private::Label()  << " Get Bottles!" << endl;
	//PairArray paint(WinePPA());
	ArrayInt a(PairArray::first().size());
	ArrayInt b(PairArray::first().size());
	for (int i = 0; i < (int)PairArray::first().size(); i++){
		cout << "Please input the year :";
		cin >> a[i];
		cout << "Please input the bottles:";
		cin >> b[i];
	}

	(PairArray &)*this = PairArray(a,b);

	cout << "End of the Get Bottles ! Thank you!\n";
	return;
}

int Wine_Private::sum()
{
	int sum = 0;
	PairArray paint = WinePPA();
	sum = paint.second().sum();
	return sum;
}

void Wine_Private::Show()
{
	cout << "The Wine " << Wine_Private::Label() << " has " << PairArray::first().size() << " years differents!\n"
		<< "\tYears\tBottles\n";
	PairArray paint = WinePPA();
	for (int i = 0; i <(int)PairArray::first().size(); i++)
		cout << "\t" << paint.first()[i] << "\t" << paint.second()[i] << endl;
	return;
}