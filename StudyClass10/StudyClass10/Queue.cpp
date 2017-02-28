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
		front = temp;//�ն���ʱ����ӵ���ͷ
	}
	else{
		rear->next = temp;//��ӵ���β
	}
	rear = temp;//�޸Ķ�β
	items++;
	return true;
}
bool Queue::dequeue(ItemQ & item){
	if (this->isempty()){
		cout << "The queue is empty,can`t dequeue anymore!\n";
		return false;
	}
	item = front->item;
	Node * temp = front;//���ڿռ����
	front = front->next;
	delete temp;//����Ԫ�ؿռ����
	items--;
	if (items == 0)
		rear = NULL;//�ն�β����
	return true;
}
void Customer::set(long when){
	processtime = std::rand() % 3 + 1;//������ô���ʱ��
	arrive = when;//���õ���ʱ��
}