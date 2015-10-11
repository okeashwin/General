#include<iostream>

class Node {
private:
	int data;
	Node *next;
public:
	int getData();
	Node *getNext();
	void setData(int);
	void setNext(Node *);
};

class LinkedList {
private:
	Node *head;
public:
	LinkedList();
	int insertIntoLL(int);
	int removeFromLL(int);
	void displayLL();
	int equalsLL(LinkedList *);
	void reverse();
	int generateCycle(int length);
	void printCycle(int LLlength, int length);
	int getLen();
	int detectCycle();
	void recoverCycle(int cycleLength);
	void pairwiseSwap();
	void returnCentre();	//Without any integer counter : constraint
	void deleteNafterM( int retain, int delete_no);
	void swapK(int pos);
	void mergeAtAlternate(LinkedList *);
	void appendAtEnd(int value);
	int isPalindrome();
	void rotateByK(int k);
	void segregateOddEven();
	LinkedList *representAdd( LinkedList *);
	void MergeAlternate(LinkedList *);

	//Stack operations for a LinkedList
	void push(int data);
	int pop();
	int peek();
	bool isEmpty();
};
