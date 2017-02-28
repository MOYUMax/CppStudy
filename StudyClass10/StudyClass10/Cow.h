#pragma once
class Cow
{
public:
	Cow();
	~Cow();
private:
	char name[20];
	char *hobby;
	double weight;
public:
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	Cow & operator=(const Cow & c);
	void ShowCow() const;
};

