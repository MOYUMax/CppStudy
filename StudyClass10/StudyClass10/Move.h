#ifndef _MOVE_H_
#define _MOVE_H_

#include "stdafx.h"

class Move{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void show()const;
	Move add(const Move &m)const;
	void reset(double a = 0, double b = 0);
};

#endif