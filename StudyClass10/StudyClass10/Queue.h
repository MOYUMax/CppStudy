#ifndef _QUEUE_H
#define _QUEUE_H

class Customer{
private:
	long arrive;
	int processtime;
public:
	Customer(){ arrive = processtime = 0; }

	void set(long when);//����ʱ��
	long when() const { return arrive; }//���ص���ʱ��
	int ptime() const { return processtime; }//���ش���ʱ��
};

typedef Customer ItemQ;

class Queue{
private:
	//���е�˽�г�Ա
	struct Node{ ItemQ item; struct Node *next; };
	enum { Q_SIZE = 10 };
	Node *front;
	Node *rear;
	int items;//��������Ԫ������
	const int qsize;
	//˽�и��ƺ����͸�ֵ��������غ�����Ϊ���Ժ�����õ���Щ����������Ϊ˽��
	Queue(const Queue &q) :qsize(0){}
	Queue & operator=(const Queue & q){ return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;//���ض�������Ԫ������
	bool enqueue(const ItemQ & item);
	bool dequeue(ItemQ & item);
};
#endif