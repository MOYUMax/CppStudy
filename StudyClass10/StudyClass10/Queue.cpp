#include "stdafx.h"
#include "Queue.h"
#include <cstdlib>

Queue::Queue(int qs) :qsize(qs){
	front = rear = NULL;
	items = 0;
}

Queue::~Queue(){
	Node *temp;
	while (front != NULL){
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty()const{
	return items == 0;
}
bool Queue::isfull()const{
	return items == qsize;
}
int Queue::queuecount()const{
	return items; 
}
bool Queue::enqueue(const ItemQ & item){
	if (this->isfull()){
		cout << "The Queue is full,can`t enqueue anymore!" << endl;
		return false;
	}
	Node *temp = new Node;
	temp->item = item;
	temp->next = NULL;
	if (this->isempty()){
		front = temp;//空队列时，入队到队头
	}
	else{
		rear->next = temp;//入队到队尾
	}
	rear = temp;//修改队尾
	items++;
	return true;
}
bool Queue::dequeue(ItemQ & item){
	if (this->isempty()){
		cout << "The queue is empty,can`t dequeue anymore!\n";
		return false;
	}
	item = front->item;
	Node * temp = front;//用于空间回收
	front = front->next;
	delete temp;//出队元素空间回收
	items--;
	if (items == 0)
		rear = NULL;//空队尾修正
	return true;
}
void Customer::set(long when){
	processtime = std::rand() % 3 + 1;//随机设置处理时间
	arrive = when;//设置到达时间
}