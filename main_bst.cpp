#include<iostream>
#include<cstdlib>
#include "bst.h"

using namespace std;

int main()
{
	BSTree b1;
	cout << b1.insertIntoBst(8) << endl;
	cout << b1.insertIntoBst(6) << endl;
	cout << b1.insertIntoBst(10) << endl;
	cout << b1.insertIntoBst(4) << endl;
	cout << b1.insertIntoBst(7) << endl;
	cout << b1.insertIntoBst(9) << endl;
	cout << b1.insertIntoBst(12) << endl;
	cout << b1.insertIntoBst(8) << endl;
	cout << b1.insertIntoBst(12) << endl;
	//cout << b1.insertIntoBst(1) << endl;	
	b1.InorderRecursive(b1.getRoot());cout << endl;
	cout << "Iterative Inorder " << endl; b1.Inorder();
	cout << endl;
	b1.PreorderRecursive(b1.getRoot());cout << endl;
	cout << "Iterative Preorder " << endl; b1.Preorder();
	cout << endl;
	b1.PostorderRecursive(b1.getRoot());cout << endl;
	cout << "Iterative Postorder " << endl; b1.Postorder();
	cout << endl;
	/*cout << b1.removeFromBst(20) << endl;
	cout << b1.removeFromBst(4) << endl;
	cout << b1.removeFromBst(11) << endl;
	cout << b1.removeFromBst(8) << endl;
	cout << b1.removeFromBst(12) << endl;*/
	/*cout << b1.inorder_successor(8) << endl;
	b1.InorderRecursive(b1.getRoot());cout << endl;
	cout << b1.MinofBST(b1.getRoot())<<endl;
	cout << b1.MaxofBST(b1.getRoot())<<endl;
	cout << b1.isBST(b1.getRoot()) << endl;
	cout << b1.size(b1.getRoot()) << endl;
	//cout << b1.getsize() << endl;
	
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	BSTree b2;
	b2.setRoot(b2.sortedToBST(b2.getRoot(),arr,0,9));
	b2.InorderRecursive(b2.getRoot());cout << endl;
	int a=3;
	int b=9;
	b2.printKeysInRange(b2.getRoot(),a,b);cout << endl;*/

}
