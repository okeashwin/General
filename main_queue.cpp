#include<iostream>
#include<cstdlib>
#include "queue.h"
using namespace std;

int main()
{
	Queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.enqueue(11);
	q1.showQueue();
	int i=0;
	for(i=0;i<7;i++)
		cout << q1.getData(q1.dequeue()) << endl;
	q1.showQueue();
}
