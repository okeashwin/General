#include<iostream>
#include<cstdlib>

using namespace std;

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
