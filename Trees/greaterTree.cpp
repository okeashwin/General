/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Problem : 
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

*/
 struct state_house{
     int holder_value;
     bool called;
 };
typedef struct state_house state_house;
class Solution {
private:
    state_house state;
    void helper(TreeNode *node) {
        if(!node) {
            return;
        }
        helper(node->right);
        if(!state.called) {
            // This must be the first call, let's bookkeep some stuff
            state.called = true;
            state.holder_value = node->val;
        }
        else {
            node->val += state.holder_value;
            state.holder_value = node->val;
        }
        helper(node->left);
    }
public:
    Solution() {
        state.holder_value = INT_MIN;
        state.called = false;
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};