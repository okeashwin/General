#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

typedef struct BSTNode {
	int value;
	struct BSTNode *left;
	struct BSTNode *right;	
}BSTNode;

BSTNode *sortedArrayToBSTHelper(int arr[], int start, int end);
BSTNode *sortedArrayToBST(int arr[], int size);
void inorder(BSTNode *root);
int inorderSuccessor(BSTNode *root, int nodeValue);

BSTNode *sortedArrayToBST(int arr[], int size)
{
	return sortedArrayToBSTHelper(arr, 0, size - 1);
}

BSTNode *sortedArrayToBSTHelper(int arr[], int start, int end)
{
	if(start > end)
		return NULL;
	int middle = start + ( end - start )/2;
	BSTNode *root = new BSTNode();
	root->value = arr[middle];
	// cout << "Pushed this to root : " << middle << " , " << arr[middle] << endl;

	// Left Subtree
	root->left = sortedArrayToBSTHelper(arr, start, middle - 1);

	// Right Subtree
	root->right = sortedArrayToBSTHelper(arr, middle + 1, end);

	return root;
}

void inorder(BSTNode *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	cout << root->value << " , ";
	inorder(root->right);
}

void inorder_iterative(BSTNode *root)
{
	if(root == NULL)
		return;
	stack<BSTNode *> nodes;
	bool completed = false;
	BSTNode *curr = root;
	// BSTNode *poppedNode = NULL;
	while(!completed)
	{
		if(curr!=NULL)
		{
			nodes.push(curr);
			curr = curr->left;
		}
		else
		{
			if(!nodes.empty())
			{
				curr = nodes.top();
				nodes.pop();
				cout << curr->value << " , ";
				curr = curr->right;
			}
			else
			{
				completed = true;
			}
		}
	}

	// Done
	cout << endl;
}

void preorder(BSTNode *root)
{
	if(root == NULL)
		return;

	cout << root->value << " , ";
	preorder(root->left);
	preorder(root->right);
}

void preorder_iterative(BSTNode *root)
{
	if(root==NULL)
		return;
	stack<BSTNode *> nodes;
	BSTNode *curr = root;
	nodes.push(curr);
	while(!nodes.empty())
	{
		curr = nodes.top();
		cout << curr->value << " , ";
		nodes.pop();
		if(curr->right)
			nodes.push(curr->right);
		if(curr->left)
			nodes.push(curr->left);
	}

	// Done
	cout << endl;
}

void postorder(BSTNode *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->value << " , ";
}


void postorder_iterative(BSTNode *root)
{
	if(root==NULL)
		return;

	stack<BSTNode *> aux1;
	stack<BSTNode *> aux2;
	BSTNode *curr = root;
	aux1.push(curr);
	while(!aux1.empty())
	{
		curr = aux1.top();
		aux1.pop();
		if(curr->left)
			aux1.push(curr->left);
		if(curr->right)
			aux1.push(curr->right);

		// Instead of printing, push it to aux2
		aux2.push(curr);
	}

	// Print out aux2
	while(!aux2.empty())
	{
		curr = aux2.top();
		cout << curr->value << " , ";
		aux2.pop();
	}	

	// Done
	cout << endl;

}

void printLevel(int level, BSTNode *root)
{
	if(root==NULL)
		return;
	if(level==0)
		cout << root->value << " , ";
	else
	{
		printLevel(level-1, root->left);
		printLevel(level-1, root->right);
	}
}

int depthBST(BSTNode *root)
{
	if(root==NULL)
		return 0;
	return max(depthBST(root->left), depthBST(root->right)) + 1;
}

void level_order_recursive(BSTNode *root)
{
	if(root==NULL)
	{
		return;
	}

	int depth = depthBST(root);
	for(int i=0;i<depth;i++)
	{
		printLevel(i, root);
	}
}

void level_order_iterative(BSTNode *root)
{
	if(root==NULL)
		return;
	queue<BSTNode *> nodes;
	BSTNode *curr = root;
	nodes.push(curr);
	while(!nodes.empty())
	{
		curr = nodes.front();
		nodes.pop();
		cout << curr->value << " , ";
		if(curr->left)
			nodes.push(curr->left);
		if(curr->right)
			nodes.push(curr->right);
	}
	// Done
	cout << endl;
}

void ksmallest(BSTNode *root, int k, int *karr)
{
	static int index = 0;
	if(root==NULL)
		return;

	ksmallest(root->left, k, karr);
	if(index < k)
	{
		karr[index] = root->value;
		index++;
	}

	ksmallest(root->right, k, karr);
}

void printArray(int *karr, int k)
{
	cout << endl;
	for(int i=0;i<k;i++)
		cout << karr[i] << " , ";
	cout << endl;
}

// Prints a specific level
// 1 for root
void printLevel(BSTNode *root, int level)
{
	int height = depthBST(root);
	if(level > height || level <= 0)
	{
		cout << "Invalid level " << endl;
		return;
	}

	if(root==NULL)
		return;
	if(level==1)
		cout << root->value << " ";
	else
	{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

int min(BSTNode *root)
{
	if(root==NULL)
		return -1;
	BSTNode *temp = root;
	while(temp->left)
		temp = temp->left;
	return temp->value;
}

int max(BSTNode *root)
{
	if(root==NULL)
		return -1;
	BSTNode *temp = root;
	while(temp->right)
		temp = temp->right;
	return temp->value;	
}

// If a tree is a BST
bool isBST(BSTNode *root)
{
	if(root==NULL)
		return true;
	if(root->left && max(root->left) > root->value)
		return false;
	if(root->right && min(root->right) < root->value)
		return false;
	return isBST(root->left) && isBST(root->right);
}

/*
A better isBST method - checks for permissible range of values at every node
*/

bool isBSTHelper(BSTNode *root, int min, int max)
{
	if(root==NULL)
		return true;

	if(root->value < min || root->value > max)
		return false;

	return isBSTHelper(root->left, INT_MIN, root->value - 1) 
			&& isBSTHelper(root->right, root->value + 1, INT_MAX);
}

bool isBST2(BSTNode *root)
{
	return isBSTHelper(root, INT_MIN, INT_MAX);
}

/*
Output the second smallest element in a BST
*/
void secondSmallestHelper(BSTNode *root, int& rank)
{
	if(root==NULL)
		return;
	// cout << "Function call : " << root->value << '\t' << rank << endl;
	secondSmallestHelper(root->left, rank);
	
	if(rank < 2)
	{
		rank++;
		if(rank==2)
			cout << root->value << endl;
	}
	// cout << "Function call continued : " << root->value << '\t' << rank << endl;
	secondSmallestHelper(root->right, rank);

}

void reverseInorder(BSTNode *root)
{
	if(root==NULL)
		return;
	reverseInorder(root->right);
	cout << root->value << " ";
	reverseInorder(root->left);
}

void secondSmallest(BSTNode *root)
{
	int rank = 0;
	secondSmallestHelper(root, rank);
}

void zigZagTraversal(BSTNode *root)
{
	if(root==NULL)
		return;
	// Declare two stacks
	queue<BSTNode *> *curr;
	queue<BSTNode *> *nextLevel;

	queue<BSTNode *> aux1;
	queue<BSTNode *> aux2;

	curr= &aux1;
	nextLevel = &aux2;

	curr->push(root);
	BSTNode *node;
	int level = 0;
	stack<BSTNode *> aux;
	while(!(curr->empty()))
	{
		node = curr->front();
		if(level%2)
			aux.push(node);
		else
			cout << node->value << " ";

		curr->pop();
		if(node->left)
			nextLevel->push(node->left);
		if(node->right)
			nextLevel->push(node->right);

		if(curr->size()==0)
		{
			curr = (curr == &aux1)? &aux2:&aux1;
			nextLevel = (nextLevel == &aux1)? &aux2:&aux1;
			level++;
			while(!(aux.empty()))
			{
				cout << (aux.top())->value << " ";
				aux.pop();
			}
			cout << endl;
		}
	}
}

void zigZagStacks(BSTNode *root)
{
	if(root==NULL)
		return;

	// Declare two stacks
	stack<BSTNode *> aux1;
	stack<BSTNode *> aux2;

	stack<BSTNode *> *curr;
	stack<BSTNode *> *nextLevel;

	curr = &aux1;
	nextLevel = &aux2;

	curr->push(root);
	int level = 1;
	BSTNode *node;
	while(!(curr->empty()))
	{
		node = curr->top();
		curr->pop();
		cout << node->value << " ";
		if(level%2)
		{
			if(node->left)
				nextLevel->push(node->left);
			if(node->right)
				nextLevel->push(node->right);
		}

		else
		{
			if(node->right)
				nextLevel->push(node->right);
			if(node->left)
				nextLevel->push(node->left);
		}

		if(curr->size()==0)
		{
			cout << endl;
			level++;
			curr = (curr == &aux1)? &aux2:&aux1;
			nextLevel = (nextLevel == &aux1)? &aux2:&aux1;
		}
	}
}

/*
Level order traversal of a tree level by level
using two queues

*/

void printLevelByLevel(BSTNode *root)
{
	if(root==NULL)
		return;
	queue<BSTNode *> *curr;
	queue<BSTNode *> *nextLevel;
	// Declare two queues
	queue<BSTNode *> aux1;
	queue<BSTNode *> aux2;

	curr = &aux1;
	nextLevel = &aux2;
	curr->push(root);
	BSTNode *dequeued;
	while(!(curr->empty()))
	{
		dequeued = curr->front();
		curr->pop();
		cout << dequeued->value << " ";

		if(dequeued->left)
			nextLevel->push(dequeued->left);
		if(dequeued->right)
			nextLevel->push(dequeued->right);

		if(curr->size()==0)
		{
			// Level needs to change and curr queue ptr needs to be swapped
			curr = (curr == &aux1)? &aux2 : &aux1;
			nextLevel = (nextLevel == &aux1)? &aux2 : &aux1;
			cout << endl;
		}
	}
}

void sumAGivenNumber(BSTNode *root, int target, int sum, vector<int>& result)
{
	if(root==NULL)
		return;

	if(sum==0)
	{
		result.push_back(root->value);
		result.push_back(target - root->value);
		// return true;
	}
	else
	{
		sumAGivenNumber(root->left, target, sum - root->value, result);
		sumAGivenNumber(root->right, target, sum - root->value, result);
	}

}

void doubleEveryNode(BSTNode *root)
{
	if(root==NULL)
		return;
	doubleEveryNode(root->left);
	doubleEveryNode(root->right);
	root->value = root->value*2;
}

void pairSum(BSTNode *root, int sum)
{
	vector<int> result;
	sumAGivenNumber(root, sum, sum, result);

	for(int i=0;i<result.size();i+=2)
		cout << "( " << result[i] << " , " << result[i+1] << " )" << endl;

}

BSTNode *findNode(BSTNode *root, int nodeValue)
{
	if(root==NULL)
		return NULL;
	if(nodeValue == root->value)
		return root;
	// Search in left subtree
	else if(nodeValue < root->value)
		return findNode(root->left, nodeValue);
	else
		return findNode(root->right, nodeValue);
}
int inorderSuccessor(BSTNode *root, int nodeValue)
{
	BSTNode *node = findNode(root, nodeValue);
	if(node==NULL)
	{
		cout << "Could not find the node" << endl;
		return -1;
	}

	if(node->right)
	{
		// Return the leftmost of the right subtree
		BSTNode *temp = node->right;
		while(temp->left)
			temp = temp->left;
		return temp->value;
	}
	else
	{
		// Start from root and return the parent of
		BSTNode *temp = root;
		BSTNode *succ = root;
		while(1)
		{
			if(temp->value==nodeValue)
				break;
			else if(nodeValue < temp->value)
			{
				succ = temp;
				temp = temp->left;
			}
			else
				temp = temp->right;
		}

		return succ->value; 
	}
}

void test()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	BSTNode *root;
	root = sortedArrayToBST(arr, 10);

	// Verify by inorder
	inorder(root);
	cout << endl;
	inorder_iterative(root);

	cout << "================PreOrder==============" << endl;
	preorder(root);
	cout << endl;
	preorder_iterative(root);

	cout << "================PostOrder==============" << endl;
	postorder(root);
	cout << endl;
	postorder_iterative(root);

	cout << "================Level Order==============" << endl;
	level_order_recursive(root);
	cout << endl;
	level_order_iterative(root);

	cout << "=================Print k smallest elements in this BST=================" << endl;
	int k = 5;
	// cin >> k;
	int *karr = new int(k);

	ksmallest(root, k, karr);
	printArray(karr, k);
	printLevel(root, 0); cout << endl;
	printLevel(root, 1); cout << endl;
	printLevel(root, 2); cout << endl;
	printLevel(root, 3); cout << endl;

	BSTNode *root2 = new BSTNode;

	cout << isBST(root) << endl;
	cout << isBST2(root) << endl;

	cout << "Second smallest : ";secondSmallest(root);

	cout << "===================== Level by level printing ===============" << endl;
	printLevelByLevel(root);
	cout << "=====================Zig zag traversal =====================" << endl;
	zigZagTraversal(root);
	cout << "====================Zig zag stacks==========================" << endl;
	zigZagStacks(root);

	pairSum(root, 7);
	cout << endl;
	cout << (40 << 2) << endl;
	cout << INT_MAX << '\t' << pow(2, sizeof(int)*8 - 1) - 1 << endl;

	cout << "============== Reverse Inorder =========================" << endl;
	reverseInorder(root); cout << endl;

	inorder_iterative(root);doubleEveryNode(root);inorder_iterative(root);
}