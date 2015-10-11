#include<iostream>
#include "llist.h"

class bst_node
{
private:
	int data;
	bst_node *left;
	bst_node *right;
public:
	int getData();
	bst_node *getLeft();
	bst_node *getRight();
	void setData(int);
	void setLeft(bst_node *);
	void setRight(bst_node *);
};

class BSTree
{
private:
	bst_node *root;
	//bst_node *getNodeHelper(bst_node *root, int data);
public:
	BSTree();
	int insertIntoBst(int data);
	bst_node *insertIntoBst(bst_node *root, int data);
	int removeFromBst(int data);
	void InorderRecursive(bst_node *root);
	void PreorderRecursive(bst_node *root);
	void PostorderRecursive(bst_node *root);
	bst_node *getRoot();
	void setRoot(bst_node *);
	int inorder_successor(int value);
	int MaxofBST(bst_node *root);
	int MinofBST(bst_node *root);
	int isBST(bst_node *root);
	int size(bst_node *root);
	int getsize();
	bst_node *sortedToBST(bst_node *root, int arr[], int start, int end);
	void printKeysInRange(bst_node *root, int& k1, int& k2);
	bst_node *getNode(int data);
	
	//Iterative traversals
	void Inorder();
	void Preorder();
	void Postorder();
};

