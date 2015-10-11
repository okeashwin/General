#include<iostream>
#include<cstdlib>
#include "llist.h"

using namespace std;

int main()
{
	LinkedList l1,l2;
	l1.insertIntoLL(1);
	l1.insertIntoLL(3);
	l1.insertIntoLL(2);
	l1.insertIntoLL(5);
	l1.insertIntoLL(4);
	l1.insertIntoLL(10);
	l1.insertIntoLL(10);
	l1.displayLL();
	int len=l1.getLen();
	/*l1.removeFromLL(1);
	l1.displayLL();
	l1.removeFromLL(5);
	l1.displayLL();
	l1.removeFromLL(10);
	l1.displayLL();
	l1.removeFromLL(7);
	l1.displayLL();
	l2.insertIntoLL(2);
	l2.insertIntoLL(3);
	//l2.insertIntoLL(4);
	//l2.insertIntoLL(10);
	//l2.insertIntoLL(7);
	l2.displayLL();
	l2.reverse();
	l2.displayLL();
	l2.reverse();
	l2.displayLL();*/
	//cout << l1.equalsLL(&l2) << endl;
	cout << l1.generateCycle(4) << endl;
	//l1.displayLL();
	l1.printCycle(len,4);
	int cycle=l1.detectCycle();
	l1.recoverCycle(cycle);
	l1.displayLL();
	l2.insertIntoLL(2);
	l2.insertIntoLL(6);
	l2.insertIntoLL(4);
	l2.displayLL();
	cout << "l2:"<< l2.detectCycle() << endl;
	//l1.pairwiseSwap();l1.displayLL();
	l1.returnCentre();
	l2.returnCentre();
	//l1.displayLL();l1.deleteNafterM(6,1);l1.displayLL();
	//l1.displayLL();l1.swapK(3);l1.displayLL();
	l1.displayLL();
	l2.displayLL();
	l1.mergeAtAlternate(&l2);
	l1.displayLL();
	l2.displayLL();
	
	return 0;
}

