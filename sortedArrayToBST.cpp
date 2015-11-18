#include <iostream>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

typedef struct BSTNode {
	int value;
	struct BSTNode *left;
	struct BSTNode *right;	
}BSTNode;

BSTNode *sortedArrayToBSTHelper(int arr[], int start, int end);
BSTNode *sortedArrayToBST(int arr[], int size);
void inorder(BSTNode *root);

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

int main()
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
	int k;
	cin >> k;
	int *karr = new int(k);

	ksmallest(root, k, karr);
	printArray(karr, k);
	printLevel(root, 1); cout << endl;
	printLevel(root, -1); cout << endl;
	printLevel(root, 2); cout << endl;
	printLevel(root, 3); cout << endl;

	BSTNode *root2 = new BSTNode;

	cout << isBST(root) << endl;
	cout << isBST2(root) << endl;
}