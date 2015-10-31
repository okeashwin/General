#include <iostream>
#include "queueUsingStacks.cpp"

using namespace std;

int main()
{
	Queue q1 = new Queue();
	int i=0;
	for(;i<5;i++)
	{
		q1.enqueue(i);
	}

	for(i=0;i<5;i++)
	{
		cout << q1.dequeue() << endl;
	}
}