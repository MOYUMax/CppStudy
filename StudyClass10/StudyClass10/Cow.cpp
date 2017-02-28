#include "stdafx.h"
#include "Cow.h"


Cow::Cow()
{
	strcpy(name,"NoName");
	hobby = new char[10];
	strcpy(hobby, "Smile");
	weight = 0.0;
}


Cow::~Cow()
{
	cout << "\tKill the cow " << name << ",his hobby is " << hobby << " and weight = " << weight << endl;
	delete[] hobby;//释放hobby的内存空间（new-delete一对一应用）
}


Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name, nm, 20);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy(hobby, ho);
	weight = wt;
}


Cow::Cow(const Cow & c)
{
	strcpy(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}


Cow & Cow::operator=(const Cow & c)
{
	//TODO: insert return statement here
	if (this == &c)
		return *this;
	strncpy(name, c.name, 20);
	delete[] hobby;
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}


void Cow::ShowCow() const
{
	cout << "The Cow name:" << name << "\n\tIt`s hobby:" << hobby << "\n\tIt`s weight = " << weight << endl;
}
