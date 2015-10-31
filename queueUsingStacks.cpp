#include <iostream>
#include <stack>

using namespace std;

class Queue
{
	private:
		stack<int> s1;
		stack<int> s2;
	public:
		void enqueue(int data);
		int dequeue();
		bool isEmpty();
		int front();
		int back();
};

void Queue::enqueue(int data)
{
	s1.push(data);
}

int Queue::dequeue()
{
	// If s2 is not empty, pop out from s2
	if(!s2.empty())
	{
		int dequeued = s2.top();
		s2.pop();
		return dequeued;
	}

	else
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		int dequeued = s2.top();
		s2.pop();
		return dequeued;
	}
}

bool Queue::isEmpty()
{
	return s1.empty() && s2.empty();
}

int Queue::front()
{

}

int Queue::back()
{

}

int main()
{
	Queue q1;
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
