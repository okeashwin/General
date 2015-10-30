#include <iostream>
#include <stack>

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
}