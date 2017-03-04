#ifndef _DCLASSIC_H
#define _DCLASSIC_H

class DCd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;

public:	
	enum { MAX = 100 };
	DCd(char *s1, char *s2, int n, double x);
	DCd(const DCd & dcd);
	DCd();
	/*char * get_performer() const{ return performers; };	
	char * get_label() const { return label; };
	int  get_selections() const{ return  selections; };
	double get_playtime() const{ return playtime; };
	bool set_performer(char * per);
	bool set_label(char * lab);
	void set_selections(int n){ selections = n; };
	void set_playtime(double x){ playtime = x; };*/
	virtual ~DCd();
	virtual void Report() const;
	virtual DCd & operator=(const DCd & dcd);
};

class DClassic :public DCd{
private:
	char  * mp;

public:
	DClassic(char * s, char * s1, char *s2, int n, double x);
	DClassic(const DClassic & c);
	DClassic();
	char * get_mp()const{ return mp; };
	virtual ~DClassic();
	virtual void Report() const;
	virtual DClassic & operator=(const DClassic & c);
};

#endif