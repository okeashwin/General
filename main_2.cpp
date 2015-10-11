#include<iostream>
#include<cstdlib>
#include "llist.h"

using namespace std;

int main()
{
	LinkedList l1;
	l1.appendAtEnd(1);
	l1.appendAtEnd(2);
	l1.appendAtEnd(3);
	//l1.appendAtEnd(3);
	//l1.appendAtEnd(2);
	//l1.appendAtEnd(1);
	l1.appendAtEnd(4);
	l1.appendAtEnd(5);
	l1.appendAtEnd(6);
	//l1.appendAtEnd(70);
	//l1.appendAtEnd(80);
	l1.displayLL();
	cout << l1.isPalindrome() << endl;
	//l1.rotateByK(4);
	l1.displayLL();
	l1.segregateOddEven();
	l1.displayLL();

	LinkedList a,b,*c;
	a.appendAtEnd(1);
	a.appendAtEnd(2);
	a.appendAtEnd(3);
	//a.appendAtEnd(13);
	//a.appendAtEnd(11);

	b.appendAtEnd(4);
	b.appendAtEnd(5);
	b.appendAtEnd(6);
	b.appendAtEnd(7);
	b.appendAtEnd(8);
	//b.appendAtEnd(8);
	//c=a.representAdd(&b);
	
	a.displayLL();	
	b.displayLL();	
	a.MergeAlternate(&b);
	a.displayLL();	
	b.displayLL();	
	//c->displayLL();
	return 0;
}
