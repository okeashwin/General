#include<iostream>
#include<cstdlib>
#include "bst.h"
//#include "llist.h"

using namespace std;

bst_node *getNodeHelper(bst_node *root, int data);
int bst_node::getData()
{	return this->data;
}

bst_node *bst_node::getLeft()
{	return this->left;
}

bst_node *bst_node::getRight()
{	return this->right;
}

void bst_node::setData(int value)
{	this->data=value;
}

void bst_node::setRight(bst_node *setR)
{	this->right=setR;
}

void bst_node::setLeft(bst_node *setL)
{	this->left=setL;
}

BSTree::BSTree()
{	this->root=NULL;
}

bst_node *BSTree::insertIntoBst(bst_node *root, int data)
{
	bst_node *new_el=new bst_node();
	bst_node *root_copy=root;
	new_el->setData(data);
	new_el->setLeft(NULL);
	new_el->setRight(NULL);
	if(root_copy==NULL)
	{
		this->root=new_el;
		//return 0;
		return this->root;
	}
	else
	{
		bst_node *temp=root_copy;
		unsigned char isDup=0;
		while(1)
		{
			if(temp->getData()==data)
			{
				isDup=1;
				break;
			}
			
			else if (data < temp->getData())
			{
				if(temp->getLeft()==NULL)
				{
					temp->setLeft(new_el);
					break;
				}
				else
					temp=temp->getLeft();
			}
			else	//Curr data element is greater
			{
				if(temp->getRight()==NULL)
				{
					temp->setRight(new_el);
					break;
				}
				else
					temp=temp->getRight();
			}
		}
		if(isDup)
			return this->root;
		else
			return this->root;
		
	}
}

void BSTree::setRoot(bst_node *root)
{
	this->root=root;
}

//returns -1 if it is a dup
int BSTree::insertIntoBst(int data)
{
	bst_node *new_el=new bst_node();
	new_el->setData(data);
	new_el->setLeft(NULL);
	new_el->setRight(NULL);
	if(this->root==NULL)
	{
		this->root=new_el;
		return 0;
	}
	else
	{
		bst_node *temp=this->root;
		unsigned char isDup=0;
		while(1)
		{
			if(temp->getData()==data)
			{
				isDup=1;
				break;
			}
			
			else if (data < temp->getData())
			{
				if(temp->getLeft()==NULL)
				{
					temp->setLeft(new_el);
					break;
				}
				else
					temp=temp->getLeft();
			}
			else	//Curr data element is greater
			{
				if(temp->getRight()==NULL)
				{
					temp->setRight(new_el);
					break;
				}
				else
					temp=temp->getRight();
			}
		}
		if(isDup)
			return -1;
		else
			return 0;
		
	}
}

void BSTree::InorderRecursive(bst_node *root)
{
	if(root==NULL)
		return;
	else
	{
		this->InorderRecursive(root->getLeft());
		//Visit the node
		cout << root->getData() << "\t";
		this->InorderRecursive(root->getRight());
	}
}

void BSTree::PreorderRecursive(bst_node *root)
{
	if(root==NULL)
		return;
	else
	{
		//M L R
		cout << root->getData() << "\t";
		this->PreorderRecursive(root->getLeft());
		this->PreorderRecursive(root->getRight());
	}
}

void BSTree::PostorderRecursive(bst_node *root)
{
	if(root==NULL)
		return;
	else
	{
		//L R M
		this->PostorderRecursive(root->getLeft());
		this->PostorderRecursive(root->getRight());
		cout << root->getData() << "\t";
	}
}

int BSTree::removeFromBst(int data)
{
	if(this->root==NULL)
		return -1;
	else
	{
		bst_node *temp=this->root;
		bst_node *parent=this->root;
		int children=0;
		unsigned char isFound=0;
		while(temp!=NULL)
		{
			if(temp->getData() < data)
			{
				parent=temp;
				temp=temp->getRight();
			}
			else if(temp->getData() > data)
			{
				parent=temp;
				temp=temp->getLeft();
			}
			else
			{
				isFound=1;
				break;
			}
		}
		if(!isFound)
			return -1;
		else
		{
			if(temp->getLeft()!=NULL && temp->getRight()!=NULL)
				children=2;
			else if(temp->getLeft()!=NULL)
			{
				if(temp->getRight()==NULL)	//should be the only case if left is not NULL
				{
					children=1;
					if(temp==parent->getLeft())
						parent->setLeft(temp->getLeft());
					else
						parent->setRight(temp->getLeft());
				}
				else
					cout << "Never here" << endl;
			}
			else if(temp->getRight()!=NULL)
			{
				if(temp->getLeft()==NULL)
				{
					children=1;
					if(temp==parent->getLeft())
						parent->setLeft(temp->getRight());
					else
						parent->setRight(temp->getRight());
				}
			}
			else	//both are NULLs and the node to be deleted is a leaf
			{
				children=0;
				if(temp==parent->getLeft())
				{	
					if(temp->getLeft()==NULL)
						parent->setLeft(NULL);
				}
				else
				{
					if(temp->getRight()==NULL)
						parent->setRight(NULL);
				}
			}

			//New if-else
			if(children<2)
				return 0;
			else
			{
				//cout << "Yet to be implemented" << endl;
				//Need the inorder successor here
				bst_node *sub=NULL;
				bst_node *sub_parent=NULL;
				if(temp==this->root)
				{
					sub=this->root->getLeft();
					sub_parent=this->root->getLeft();
					//New Root
					while(sub->getRight()!=NULL)
					{
						sub_parent=sub;
						sub=sub->getRight();
					}
					//sub is to be replaced
					sub_parent->setRight(NULL);
					sub->setLeft(this->root->getLeft());
					sub->setRight(this->root->getRight());
					this->root=sub;
					
				}
				else
				{
				}
				return -10;
			}
		}
	}
}

bst_node *BSTree::getRoot()
{	return this->root;
}

int BSTree::inorder_successor(int value)
{
	bst_node *temp=this->root;
	if(temp==NULL)
		return -1;
	else
	{
		//Search for the element first
		bst_node *temp2=this->root;
		while(temp!=NULL)
		{
			if(value < temp->getData())
				temp=temp->getLeft();
			else if(value > temp->getData())
				temp=temp->getRight();
			else
				break;
		}
		if(temp==NULL)
			return -1;
		else
		{
			//temp points to the data whose inorder successor needs to be found
			//Check if temp->right is Null
			//If not, go to the leftmost child in the right subtree
			if(temp->getRight()!=NULL)
			{
				bst_node *node_right=temp->getRight();
				while(node_right->getLeft())
					node_right=node_right->getLeft();
				return node_right->getData();
			}
			else
			{
				//Traverse down the tree. Return the parent of the node, which is the left child of it's parent
				bst_node *succ=this->root;
				temp=this->root;
				while(temp->getData()!=value)
				{
					if(temp->getData() < value)
					{
						succ=temp;
						temp=temp->getLeft();
					}
					else
						temp=temp->getRight();
				}
				return succ->getData();
			}
		}
		
	}
	
}

int BSTree::MaxofBST(bst_node *root)
{
	bst_node *temp=root;
	while(temp->getRight()!=NULL)
		temp=temp->getRight();
	return temp->getData();
}

int BSTree::MinofBST(bst_node *root)
{
	bst_node *temp=root;
	while(temp->getLeft()!=NULL)
		temp=temp->getLeft();
	return temp->getData();
}

//returns 1 if the given BT is a BST
//else returns 0
int BSTree::isBST(bst_node *root)
{
	bst_node *temp=root;
	if(temp==NULL)
		return 1;
	else
	{
		if(temp->getLeft()!=NULL && MaxofBST(temp->getLeft()) > temp->getData())	//Max of left subtree should be less than the root for it to be a valid BST
			return 0; 
		if(temp->getRight()!=NULL && MinofBST(temp->getRight()) < temp->getData())
			return 0;
		if(isBST(temp->getLeft())==0 || isBST(temp->getRight())==0)
			return 0;
		return 1;
	}
}

int BSTree::size(bst_node *root)
{
	if(root==NULL)
		return 0;
	else
		return size(root->getLeft()) + size(root->getRight()) + 1;
}

int BSTree::getsize()
{
	/*bst_node *temp=this->root;
	if(temp==NULL)
		return 0;
	else
	{
		bst_node *left=temp->getLeft();
		bst_node *right=temp->getRight();
		return left->getsize() + right->getsize() + 1;
	}*/
}

//Works. Good going
bst_node *BSTree::sortedToBST(bst_node *root, int arr[], int start, int end)
{
	if(start>end)
		return NULL;
	else
	{
		int middle=start + (end-start)/2;
		root=insertIntoBst(root,arr[middle]);
		root->setLeft(sortedToBST(root->getLeft(),arr, start, middle-1));
		root->setRight(sortedToBST(root->getRight(), arr, middle+1, end));
		return root;
	}
}

void BSTree::printKeysInRange(bst_node *root, int& k1, int& k2)
{
	if(root==NULL)
		return;
	else
	{
		printKeysInRange(root->getLeft(),k1,k2);
		if(root->getData() >= k1 && root->getData() <= k2)
			cout << root->getData() << " ";
		printKeysInRange(root->getRight(),k1,k2); 
	}
}

// Iterative Inorder
void BSTree::Inorder()
{
	bst_node *temp=this->root;
	if(temp==NULL)
	{
		cout << "Tree Empty" << endl;
		//return
	}

	else
	{
		//We need a stack here
		bst_node *parent=this->root;
		LinkedList stack;
		bool done=false;
		while(!done)
		{
			if(temp!=NULL)
			{
				stack.push(temp->getData());
				temp=temp->getLeft();
			}
			
			else
			{
				if(!stack.isEmpty())
				{
				int pop=stack.pop();
				cout << pop << "\t";
				temp=getNode(pop);
				if(temp==NULL)
					cout << "Temp NULL " << endl;
				else
					temp=temp->getRight();
				}

				else
					done=true;
			}
		}
		cout << endl;
	}
}

bst_node *BSTree::getNode(int data)
{
	if(this->root==NULL)
		return NULL;
	else
	{
		bst_node *result;
		result=getNodeHelper(this->root,data);
	}
}

bst_node *getNodeHelper(bst_node *root, int data)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(data==root->getData())
			return root;

		bst_node *result;
		result=getNodeHelper(root->getLeft(),data);
		if(result==NULL)
			result=getNodeHelper(root->getRight(),data);

		return result;
	}
}

void BSTree::Preorder()
{
	if(this->root==NULL)
		return;
	else
	{
		LinkedList stack;
		bst_node *temp=this->root;
		stack.push(this->root->getData());
		while(!stack.isEmpty())
		{
			int pop = stack.pop();
			cout << pop << "\t";
			temp=getNode(pop);
			if(temp->getRight() != NULL)
				stack.push(temp->getRight()->getData());
			if(temp->getLeft() != NULL)
				stack.push(temp->getLeft()->getData());
		}
		cout << endl;
		return;
	}
}

void BSTree::Postorder()
{
	if(this->root==NULL)
		return;
	else
	{
		LinkedList stack1, stack2;
		bst_node *temp=this->root;
		int size=this->size(this->root);
		cout << size << endl;
		int i=0;
		stack1.push(this->root->getData());
		while(!stack1.isEmpty())
		{
			int pop= stack1.pop();
			//cout << "Peek element : " << pop << endl;
			temp = getNode(pop);
			if(temp->getLeft() != NULL)
				stack1.push(temp->getLeft()->getData());
			if(temp->getRight() != NULL)
				stack1.push(temp->getRight()->getData());
			stack2.push(pop);
		}
		while(!stack2.isEmpty())
			cout << stack2.pop() << "\t";

		cout << endl;
		return;
	}
}
