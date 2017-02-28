#ifndef _QUEUE_H
#define _QUEUE_H

class Customer{
private:
	long arrive;
	int processtime;
public:
	Customer(){ arrive = processtime = 0; }

	void set(long when);//设置时间
	long when() const { return arrive; }//返回到达时间
	int ptime() const { return processtime; }//返回处理时间
};

typedef Customer ItemQ;

class Queue{
private:
	//队列的私有成员
	struct Node{ ItemQ item; struct Node *next; };
	enum { Q_SIZE = 10 };
	Node *front;
	Node *rear;
	int items;//队列现有元素数量
	const int qsize;
	//私有复制函数和赋值运算符重载函数，为了以后可能用到这些函数而设置为私有
	Queue(const Queue &q) :qsize(0){}
	Queue & operator=(const Queue & q){ return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;//返回队列现有元素数量
	bool enqueue(const ItemQ & item);
	bool dequeue(ItemQ & item);
};
#endif