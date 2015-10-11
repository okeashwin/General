#include<iostream>
#include<cstdlib>
#include "queue.h"

using namespace std;
/*
typedef struct node {
	int data;
	struct node *next;
}Node;

class Queue {
private:
	Node *head;
	Node *tail;
public:
	Queue();
	Node *getHead();
	Node *getTail();
	int enqueue(int data);
	Node *dequeue();
	void showQueue();
	int getData(Node *temp);
};
*/

//Tp tester
int Queue::getData(Node *temp)
{
	if(temp==NULL)
		return -10;
	else
		return temp->data;
}
Queue::Queue()
{
	this->head=NULL;
	this->tail=NULL;
}

Node *Queue::getHead()
{
	return this->head;
}

Node *Queue::getTail()
{
	return this->tail;
}

int Queue::enqueue(int data)
{
	//enqueue at tail
	Node *new_el=new Node();
	new_el->data=data;
	new_el->next=NULL;
	if(this->head==NULL)
	{
		this->head=new_el;
		this->tail=new_el;
	}

	else
	{
		Node *temp=this->tail;
		temp->next=new_el;
		this->tail=new_el;
	}
	
}

Node *Queue::dequeue()
{
	//dequeue from head
	if(this->head==NULL)
		return NULL;
	else
	{
		Node *temp=this->head;
		this->head=this->head->next;
		return temp;
	}
}

void Queue::showQueue()
{
	if(this->head==NULL)
		return;
	else
	{
		Node *temp=this->head;
		while(temp!=NULL)
		{
			cout << temp->data <<" --> ";
			temp=temp->next;
		}
		cout << "NULL" << endl;
		return;
	}	
}
