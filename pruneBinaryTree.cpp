/*
Prune a tree. slice off the tree below a level H
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
} BSTNode;

void pruneTree(BSTNode *root, int thresh);
BSTNode *insert(int data);
void printInorder(BSTNode *root);
vector<BSTNode *> getLevelNodes(BSTNode *root, int level);
void getLevelNodesHelper(BSTNode *root, int level, vector<BSTNode *>& nodes);
void printVec(vector<BSTNode *> nodes);
int getHeight(BSTNode *root);
void postOrderDelete(BSTNode *node);


void pruneTree(BSTNode *root, int thresh)
{
	if(thresh > getHeight(root))
		return;
	// Get all the nodes at level 'thresh'
	vector<BSTNode *> nodesAtLevel = getLevelNodes(root, thresh);

	// For every child node, call delete
	for(int i=0;i < nodesAtLevel.size(); i++)
	{
		postOrderDelete(nodesAtLevel[i]->left);
		postOrderDelete(nodesAtLevel[i]->right);
		nodesAtLevel[i]->left = NULL;
		nodesAtLevel[i]->right = NULL;

	}

	return;
}

void postOrderDelete(BSTNode *node)
{
	if(node==NULL)
		return;
	postOrderDelete(node->left);
	postOrderDelete(node->right);
	// cout << "Deleting Node " << node->data << endl;
	delete node;
}

int getHeight(BSTNode *root)
{
	if(root==NULL)
		return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

vector<BSTNode *> getLevelNodes(BSTNode *root, int level)
{
	if(level > getHeight(root))
	{
		cout << "Level provided greater than the height of the tree " << endl;
		return vector<BSTNode *>();
	}
	vector<BSTNode *> result;
	getLevelNodesHelper(root, level, result);
	return result;
}

void getLevelNodesHelper(BSTNode *root, int level, vector<BSTNode *>& nodes)
{
	if(root==NULL)
		return;
	if(level == 1)
		nodes.push_back(root);
	else
	{
		getLevelNodesHelper(root -> left, level - 1, nodes);
		getLevelNodesHelper(root -> right, level - 1, nodes);
	}
}

void printVec(vector<BSTNode *> nodes)
{
	if(nodes.size() == 0)
	{
		cout << "Empty Vector" << endl;
		return;
	}
	for(int i=0;i< nodes.size(); i++)
		cout << nodes[i]->data << " ";
	cout << endl;
}

BSTNode *insert(int data)
{
	BSTNode *new_el = new BSTNode();
	new_el->data = data;
	new_el->left = NULL;
	new_el->right = NULL;
}

void printInorder(BSTNode *root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);

}
int main()
{
	BSTNode *root;
	root = insert(20);
	root->left = insert(21);
	root->right = insert(22);

	root->left->left = insert(23);
	root->right->right = insert(24);
	root->left->left->left = insert(25);
	root->right->right->right = insert(26);
	printInorder(root);
	cout << endl;

	// for(int i=1;i < getHeight(root) + 5; i++)
	// {
	// 	cout << "Level " << i << endl;
	// 	nodes.clear();
	// 	nodes = getLevelNodes(root, i);
	// 	printVec(nodes);
	// }

	pruneTree(root, 3);
	printInorder(root); cout << endl;

}