#include<iostream>
#include<stdlib.h>
#include<cmath>
#include "llist.h"

using namespace std;

int Node::getData()
{	return this->data;
}

Node *Node::getNext()
{	return this->next;
}

void Node::setData(int value)
{
	this->data=value;
}

void Node::setNext(Node *nxtNode)
{
	this->next=nxtNode;
}

LinkedList::LinkedList()
{	
	this->head=NULL;
}

//Returns 0 on successful insertion
//Returns 1 if it is a duplicate
int LinkedList::insertIntoLL(int value)
{
	//Dups not allowed
	Node *temp=this->head;
	Node *new_el=new Node();
	new_el->setData(value);
	new_el->setNext(NULL);
	if(temp==NULL)	//1st element
		this->head=new_el;
	else		//Not the 1st
	{
		Node *prev=this->head;
		Node *curr=this->head;
		int isNull=0;
		int isDup=0;
		while(curr->getData()<=value)
		{
			//Check for the dup first
			if(curr->getData()==value)
			{
				isDup=1;
				break;
			}
			//Increment pointers
			prev=curr;
			curr=curr->getNext();
			if(curr==NULL)
                        {
                                isNull=1;
                                break;
                        }
		}
		if(isDup)
		{
			cout << "The element is a duplicate"<<endl;
			return 1;
		}
		if(isNull)	//curr is NULL, prev is the last element
			prev->setNext(new_el);
		else
		{
			//prev->getNext()=new_el;
			prev->setNext(new_el);	
			//new_el->getNext()=curr;
			new_el->setNext(curr);
		}
	}

	cout<<"Successfully inserted "<<value<<" into the LL"<<endl;
	return 0;

} 

//Returns 0 if element is successfully deleted
//Returns 1 if the element is not found
int LinkedList::removeFromLL(int value)
{
	Node *temp=this->head;
	if(temp==NULL)
	{
		cout << "LL is empty"<<endl;
		return 1;
	}
	else
	{
		Node *curr=this->head;
		Node *prev=this->head;
		int isNull=0;
		while(curr->getData()!=value)
		{
			prev=curr;
			curr=curr->getNext();
			if(curr==NULL)
			{
				isNull=1;
				break;
			}
		}
		if(isNull)	//curr is NULL
		{
			cout << "Element not found"<<endl;
			return 1;
		}
		if(curr==this->head)		//1st element
			this->head=this->head->getNext();
		else if(curr->getNext()==NULL)	//last element
			prev->setNext(NULL);
		else		//gotta the element, position somewhere in the middle
			prev->setNext(curr->getNext());
		cout << "Element "<<value<<" successfully deleted"<<endl;
		return 0;
	}
}

void LinkedList::displayLL()
{
	Node *temp=this->head;
	if(temp==NULL)
		cout<<"LL is empty"<<endl;
	else
	{
		while(temp!=NULL)
		{
			cout << temp->getData()<<" --> ";
			temp=temp->getNext();
		}
		cout << "NULL"<<endl;
	}
}

//Returns 0 if equal
//Returns -1 if both are empty
//Else returns the position at which the 1st difference is found, 1 is root
int LinkedList::equalsLL(LinkedList *l2)
{
	Node *head1=this->head;
	Node *head2=l2->head;
	int diffPosition=0;
	int temp1isNull=0;
	int temp2isNull=0;
	//Basic checks
	if(head2==NULL && head1!=NULL)
		return 1;
	else if(head1==NULL && head2!=NULL)
		return 1;
	else if(head1==NULL && head2==NULL)
		//Empty
		return -1;
	else
	{
		//int len1=0;
		//int len2=0;
		Node *temp1=head1;
		Node *temp2=head2;
		/*while(temp1!=NULL)
		{
			len1++;
			temp1=temp1->getNext();
		}
		while(temp2!=NULL)
		{
			len2++;
			temp2=temp2->getNext();
		}*/

		while(temp1->getData()==temp2->getData())
		{
			diffPosition++;
			temp1=temp1->getNext();
			temp2=temp2->getNext();
			if(temp1==NULL)
				temp1isNull=1;
			if(temp2==NULL)
				temp2isNull=1;
			if(temp1isNull==1 || temp2isNull==1)
				break;
		}
		if(temp1==head1 && temp2==head2)
			diffPosition=1;
		if(temp1isNull)
		{
			if(temp2isNull)
				return 0;
			else
				return diffPosition;
		}
		if(temp2isNull)
		{
			if(temp1isNull)
				return 0;
			else
				return diffPosition;
		}
		
	}
}

//Reverses the given LL
void LinkedList::reverse()
{
	Node *temp_head=this->head;
	if(temp_head==NULL)	//empty - already reversed
		return;
	else if(temp_head->getNext()==NULL)	//single element - already reversed
		return;
	else if(temp_head->getNext()->getNext()==NULL)	//Two elements
	{
		Node *temp=temp_head;
		this->head=this->head->getNext();
		this->head->setNext(temp);
		temp->setNext(NULL);
	}

	else	//More than two elements
	{
		Node *prev=this->head;
		Node *curr=this->head;
		//Set curr to the third element
		curr=curr->getNext()->getNext();
		prev=curr;
		Node *temp=this->head;
		this->head=this->head->getNext();
		this->head->setNext(temp);
		temp->setNext(NULL);
		//two elements done

		while(curr!=NULL)
		{
			curr=curr->getNext();
			prev->setNext(this->head);
			this->head=prev;
			prev=curr;
		}
	}
}

//Returns 0 on successful cycle generation
//Returns -1 on failure
int LinkedList::generateCycle(int length)
{
	if(length==0)
		return 0;
	else
	{
		Node *temp=this->head;
		int LLlength=0;
		if(temp==NULL)
			//Cycle cannot be generated
			return -1;
		else
		{
			while(temp!=NULL)
			{
				LLlength++;
				temp=temp->getNext();
			}
			//cout << "LLength : "<<LLlength << endl;
			if(LLlength<length)
				//Cycle not possible to generate
				return -1;
			else
			{
				temp=this->head;
				int tempToMove=LLlength-length+1;
				//cout << "temptomove "<<tempToMove<<endl;
				int i=1;
				while(i<tempToMove)
				{
					temp=temp->getNext();
					i++;
				}
				//temp is at the required position now
				Node *cycleInitiator=temp;
				while(temp->getNext()!=NULL)
					temp=temp->getNext();
				//Form the cycle
				temp->setNext(cycleInitiator);
				//Cycle done
				return 0;
			}
		}		
	}
}

int LinkedList::getLen()
{
	Node *temp=this->head;
	if(temp==NULL)
		return 0;
	else
	{
		int LLlength=0;
		while(temp!=NULL)
		{
			LLlength++;
			temp=temp->getNext();
		}
		return LLlength;
	}
}
void LinkedList::printCycle(int LLlength, int length)
{
	Node *temp=this->head;
	if(temp==NULL)
		return;
	else
	{
		if(length==0)
			this->displayLL();
		else
		{
			int toPrint=LLlength+length;
			int i=1;
			temp=this->head;
			while(i<=toPrint)
			{
				cout << temp->getData() << "-->";
				temp=temp->getNext();
				i++;
			}
			cout << " ..."<<endl;
		}
	}
}

//Returns the length of the cycle, 0 if no cycle is present
int LinkedList::detectCycle()
{
	Node *temp=this->head;
	Node *slow=this->head;
	Node *fast=slow->getNext();
	int Mfactor=1;
	unsigned char fastIsNull=0;
	int cycleLength=0;
	unsigned char cycleDetected=0;
	int i=1;
	while(1)
	{
		slow=slow->getNext();
		for(i=1;i<=Mfactor;i++)
		{
			fast=fast->getNext();
			if(fast==NULL)
			{	fastIsNull=1;
				break;
			}
			if(fast==slow)
			{
				cycleDetected=1;
				break;
			}
		}
		if(fastIsNull)
			break;
		if(cycleDetected)
			break;
		else
			Mfactor=Mfactor*2;
	}
	if(cycleDetected)
	{
		slow=slow->getNext();
		cycleLength++;
		while(fast!=slow)
		{
			slow=slow->getNext();
			cycleLength++;
		}
		return cycleLength;
	}
	else
	{
		//Sanity
		if(fast==NULL)
			return 0;
	}
}

void LinkedList::recoverCycle(int cycleLength)
{
	if(cycleLength==0)
		return;
	else
	{
		Node *temp=this->head;
		Node *prev=this->head;
		Node *curr=this->head;
		int i=1;
		while(i<=cycleLength)	//Should be at 'cyclelength + 1' position
		{
			prev=curr;
			curr=curr->getNext();
			i++;
		}

		while(temp!=curr)		//Eventually temp and curr meet at the initiating point of the cycle
		{
			temp=temp->getNext();
			prev=curr;
			curr=curr->getNext();
		}

		//Recover the cycle
		prev->setNext(NULL);
	}
}

//Pairwise swap
void LinkedList::pairwiseSwap()
{
	Node *swap1=this->head;
	Node *swap2=this->head;
	Node *temp=this->head;
	if(temp==NULL)	//Empty LL
		return;
	else if(temp->getNext()==NULL)	//Only 1 element
		return;
	else
	{
		swap2=swap1->getNext();
		swap1->setNext(swap2->getNext());
		swap2->setNext(swap1);
		this->head=swap2;
		swap1=swap1->getNext();
		swap2=swap2->getNext()->getNext()->getNext();
		if(swap1==NULL)	//LL has 2 elements
			return;
		else if(swap2==NULL)	// LL has 3 elements
			return;
		else	//More than 3 elements
		{
			temp=this->head->getNext();
			while(1)
			{	
				swap1->setNext(swap2->getNext());
				swap2->setNext(swap1);
				temp->setNext(swap2);
				swap1=swap1->getNext();
				if(swap1==NULL)
					break;
				swap2=swap2->getNext()->getNext()->getNext();
				if(swap2==NULL)
					break;
				temp=temp->getNext()->getNext();
			}
			return;		
		}
	}
}

//Without integer counter
void LinkedList::returnCentre()
{
	Node *slow=this->head;
	Node *fast=this->head;
	while(fast->getNext()!=NULL)
	{
		slow=slow->getNext();
		fast=fast->getNext();
		if(fast->getNext()==NULL)
			break;
		fast=fast->getNext();
	}
	cout << "Center of the LL is " << slow->getData() << endl;
}

void LinkedList::deleteNafterM(int retain, int delete_no)
{
	Node *temp=this->head;
	if(temp==NULL)
		return;
	else
	{
		Node *len=this->head;
		int length=0;
		while(len!=NULL)
		{
			length++;
			len=len->getNext();
		}
		if(retain>=length)
			return;
		else
		{
		Node *nextPos=this->head;
		unsigned char LLend=0;
		int i=0;
		int j=0;
		while(1)
		{
			for(i=0;i<retain-1;i++)
			{
				temp=temp->getNext();
				//nextPos=nextPos->getNext();
				if(temp==NULL)
				{
					LLend=1;
					break;
				}
			}
			if(LLend)
				break;
			nextPos=temp;
			for(j=0;j<delete_no;j++)
			{
				nextPos=nextPos->getNext();
				if(nextPos==NULL)
				{
					LLend=1;
					break;
				}
			}
			if(LLend)
				break;
			//Else need to delete elements
			temp->setNext(nextPos->getNext());
			temp=nextPos->getNext();
			if(temp==NULL)
				break;
		}
		}
	}
}

void LinkedList::swapK(int pos)
{
	int length=0;
	int i=0;
	int retro_pos=0;
	Node *swpA, *swpB, *prevswpA, *prevswpB;
	Node *temp=this->head;
	while(temp!=NULL)
	{
		length++;
		temp=temp->getNext();
	}
	temp=this->head;
	if(temp==NULL)
		return;
	else
	{
		if(pos>length)
			return;
		else
		{
			retro_pos=length-pos+1;
			//Get to the correct positions
			temp=this->head;
			for(i=0;i<pos-2;i++)
				temp=temp->getNext();
			prevswpA=temp;
			swpA=prevswpA->getNext();
			i=0;
			temp=this->head;
			for(i=0;i<retro_pos-2;i++)
				temp=temp->getNext();
			prevswpB=temp;
			swpB=prevswpB->getNext();
			//Positions are got correctly

			//Special cases
			if(pos==1 || pos==length)	//Needs to be swapped with the last element
			{
				temp=this->head;
				Node *a=this->head;
				Node *prevb, *b;
				prevb=this->head;
				b=this->head;
				while(b->getNext()!=NULL)
				{
					prevb=b;
					b=b->getNext();
				}
				//Swapping
				prevb->setNext(NULL);
				b->setNext(a->getNext());
				a->setNext(NULL);
				prevb->setNext(a);
				this->head=b;
			}

			else
			{
				if(swpA->getNext()==swpB || swpB->getNext()==swpA)
				{
					if(swpA->getNext()==swpB)
					{
						Node *bnext=swpB->getNext();
						prevswpA->setNext(swpB);
						swpA->setNext(bnext);
						swpB->setNext(swpA);
					}
					else
					{
						//swpB->getNext()==swpA
						Node *anext=swpA->getNext();
						prevswpB->setNext(swpA);
						swpB->setNext(anext);
						swpA->setNext(swpB);
					}
				}
				else
				{
				prevswpA->setNext(swpA->getNext());
				swpA->setNext(NULL);
				
				prevswpB->setNext(swpB->getNext());
				swpB->setNext(NULL);

				Node *a_next=prevswpB->getNext();
				Node *b_next=prevswpA->getNext();
			
				prevswpB->setNext(swpA);
				swpA->setNext(a_next);

				prevswpA->setNext(swpB);
				swpB->setNext(b_next);
				}
			}
		}
	}
}

void LinkedList::mergeAtAlternate(LinkedList *l2)
{
	Node *head1=this->head;
	Node *head2=l2->head;
	Node *nextPos1=head1->getNext();
	Node *nextPos2=head2->getNext();
	Node *new_head2=l2->head;
	unsigned char l2IsEmpty=0;
	//l1 has to be changed. Insertion to be in place. l2's elements at alternate positions
	if(head1==NULL)
		return;
	else if(head2==NULL)
		return;
	else
	{
		while(nextPos1!=NULL)
		{
			//Time to replace
			cout << "head1 data "<<head1->getData() << " nextpos1 : "<<nextPos1->getData() << " head2 data : " << head2->getData() << endl;
			head1->setNext(head2);
			new_head2=l2->head->getNext();
			head2->setNext(nextPos1);
			head1=nextPos1;
			nextPos1=nextPos1->getNext();
			l2->head=new_head2;
			head2=new_head2;
			if(l2->head==NULL)
			{	l2IsEmpty=1;
				break;
			}
				
		}
		return;
	}
}

void LinkedList::appendAtEnd(int value)
{
	Node *temp=this->head;
	Node *new_el=new Node();
	new_el->setData(value);
	new_el->setNext(NULL); 
	if(temp==NULL)
		this->head=new_el;
	else
	{
		while(temp->getNext()!=NULL)
			temp=temp->getNext();
		//temp is now at the last element
		temp->setNext(new_el);
		new_el->setNext(NULL);
	}
}

//Stack operations
void LinkedList::push(int data)
{
	Node *new_el=new Node();
	new_el->setData(data);
	new_el->setNext(NULL);
	if(this->head==NULL)
		this->head=new_el;
	else
	{
		Node *temp=this->head;
		this->head=new_el;
		new_el->setNext(temp);
	}
}

//Returns -1 upon stack empty
//Else returns the data value
int LinkedList::pop()
{
	Node *temp=this->head;
	if(this->head==NULL)
		return -1;
	else
	{
		this->head=this->head->getNext();
		return temp->getData();
	}
}

//Returns 0 when not
int LinkedList::isPalindrome()
{
	Node *slow=this->head;
	Node *fast=this->head;
	Node *slow_prev=this->head;
	LinkedList temp_stack;
	int length=0;
	if(this->head==NULL)
		return 0;
	else
	{
		unsigned char res=1;
		int pop=0;
		while(fast!=NULL)
		{
			fast=fast->getNext();
			length++;
			if(fast==NULL)
				break;
			fast=fast->getNext();
			length++;
			if(fast==NULL)
				break;
			temp_stack.push(slow->getData());
			slow_prev=slow;
			slow=slow->getNext();
		}
		cout << slow_prev->getData() << endl;
		//temp_stack should now have half of the elements
		if(length%2==0)
			//slow=slow_prev;
			temp_stack.push(slow->getData());
		while(slow->getNext()!=NULL)
		{
			slow=slow->getNext();
			pop=temp_stack.pop();
			if(pop!=slow->getData())
			{
				res=0;
				break;
			}
		}
		return res;
	}
}

void LinkedList::rotateByK(int k)
{
	if(this->head==NULL)
		return;
	else
	{
		Node *temp_head=this->head;
		Node *temp=this->head;
		Node *tail=this->head;
		while(tail->getNext()!=NULL)
			tail=tail->getNext();
		//tail now points to the last element
		int len=0;
		while(temp!=NULL)
		{	temp=temp->getNext();
			len++;
		}
		if(k>len)
		{
			cout << "K greater than the length of the LL" << endl;
			return;
		}
		else if(k==len)
			reverse();
		else
		{
			int i=0;
			temp=this->head;
			for(i=0;i<k;i++)
			{
				this->head=this->head->getNext();
				temp->setNext(NULL);
				tail->setNext(temp);
				tail=tail->getNext();
				temp=this->head;
			}
		}
	}
}

void LinkedList::segregateOddEven()
{
	if(this->head==NULL)
		return;
	else
	{
		Node *odd=this->head;
		Node *even=this->head;
		Node *tail=this->head;
		//All evens should be before the odds
		while(tail->getNext()!=NULL)
			tail=tail->getNext();
		Node *prev_odd=this->head;
		Node *init_tail=tail;
		while(odd!=init_tail)
		{
			//Core operations
			if(odd->getData()%2==1)
			{
				//cout << "Here" << endl;
				if(odd==this->head)
				{
					this->head=this->head->getNext();
					odd->setNext(NULL);
					tail->setNext(odd);
					tail=tail->getNext();
					prev_odd=this->head;
					odd=this->head;
				}
				else
				{
				Node *odd_next=odd->getNext();
				prev_odd->setNext(odd->getNext());
				odd->setNext(NULL);
				tail->setNext(odd);
				tail=tail->getNext();
				odd=odd_next;
				}
			}
			else
			{
				prev_odd=odd;
				odd=odd->getNext();
			}
		}
		
	}
}

//Addition representation
LinkedList *LinkedList::representAdd(LinkedList *l2)
{
	Node *l1_head=this->head;
	Node *l2_head=l2->head;
	if(l1_head==NULL)
		return l2;
	else if(l2_head==NULL)
		return this;
	else
	{
		int number1=0;
		int number2=0;
		int result=0;
		Node *temp1=l1_head;
		Node *temp2=l2_head;
		int i=0;
		while(temp1!=NULL)
		{
			number1=number1+temp1->getData()*pow(10,i);
			i++;
			temp1=temp1->getNext();
		}
		temp1=l1_head;i=0;
		while(temp2!=NULL)
		{
			number2=number2+temp2->getData()*pow(10,i);
			i++;
			temp2=temp2->getNext();
		}
		temp2=l2_head;i=0;
		//number1 and number2 are ready
		
		result=number1+number2;
		LinkedList result_list;
		int data=0;
		int temp_result=result;
		while(temp_result!=0)
		{
			data=temp_result%10;
			result_list.appendAtEnd(data);
			temp_result=temp_result/10;
		}
		return &result_list;
	}
}

void LinkedList::MergeAlternate(LinkedList *l2)
{
	Node *temp1=this->head;
	Node *temp2=l2->head;
	if(temp2==NULL)
		return;
	else
	{
		Node *prev_temp2=l2->head;
		Node *prev_temp1=this->head;
		temp1=temp1->getNext();
		while(temp1!=NULL && temp2!=NULL)
		{
			if(temp2==l2->head)
			{
				//cout << "Here always" << endl;
				Node *temp2_next=temp2->getNext();
				l2->head=l2->head->getNext();
				prev_temp1->setNext(temp2);
				temp2->setNext(temp1);
				prev_temp1=temp1;
				temp1=temp1->getNext();
				temp2=temp2_next;
				//The first time temp1 becomes NULL, we still have a place here
				if(temp1==NULL)
				{
				Node *temp2_next=temp2->getNext();
				l2->head=l2->head->getNext();
				prev_temp1->setNext(temp2);
				temp2->setNext(temp1);
				prev_temp1=temp1;
				//temp1=temp1->getNext();
				temp2=temp2_next;
				}
				
			}
		}
	}
}

//Returns the element on the top
int LinkedList::peek()
{
	if(this->head==NULL)
		return -10;
	else
		return this->head->getData(); 
}

//isEmpty
bool LinkedList::isEmpty()
{
	if(this->head==NULL)
		return true;
	else
		return false;
}
