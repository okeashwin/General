#include<iostream>
using namespace std;

void fizzbuzz(int n)
{
	if(n%15==0)
		cout << "Fizz Buzz" << endl;
	else if(n%3==0)
		cout << "Fizz" << endl;
	else if(n%5==0)
		cout << "Buzz" << endl;
}

int main()
{
	fizzbuzz(15);
	fizzbuzz(30);
	fizzbuzz(6);
	fizzbuzz(5);
	fizzbuzz(4);
}
