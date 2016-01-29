// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

//       A
//      /  \
//   B      C
//  /      /  \
// D     E     F


// ABD
// ACE
// ACF
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void pathHelper(TreeNode *root, string currPath) {
    if(root==NULL) {
        return;
    }
    if(root->left==NULL && root->right==NULL) {
        currPath.insert(currPath.end(), root->val);
        cout<<currPath<<endl;
        return;
    }
    currPath.insert(currPath.end(), root->val);
    pathHelper(root->left, currPath);
    pathHelper(root->right, currPath);
}

void printAllPaths(TreeNode *root) {
    string currPath;
    pathHelper(root, currPath);
}

int main() {
    TreeNode *root=new TreeNode;
    root->left=new TreeNode;
    root->right=new TreeNode;
    root->left->left=new TreeNode;
    root->right->left=new TreeNode;
    root->right->right=new TreeNode;
    
    root->val='A';
    root->left->val='B';
    root->right->val='C';
    root->left->left->val='D';
    root->right->left->val='E';
    root->right->right->val='F';
    
    printAllPaths(root);
    return 0;
    
}