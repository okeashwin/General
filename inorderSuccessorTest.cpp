#include<iostream>
#include "sortedArrayToBST.cpp"

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	BSTNode *root;
	root = sortedArrayToBST(arr, 10);
	cout << "===================== Level by level printing ===============" << endl;
	printLevelByLevel(root);
	for(int i=1;i<=10;i++)
		cout << "inorderSuccessor("<<i<<") " << inorderSuccessor(root,i) << endl;
}