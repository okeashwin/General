class Solution {
private:
    void treeHelper(TreeNode *root, string currPath, vector<string>& result)
    {
        if(root==NULL)
            return;
        
        currPath.append(to_string(root->val));
        cout << root->val+"->" << endl;
        if(root->left==NULL && root->right==NULL)
        {
            // Push currPath to results;
            result.push_back(currPath);
        }
        else
            currPath.append("->");
        
        // Recur
        treeHelper(root->left, currPath, result);
        treeHelper(root->right, currPath, result);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string currPath="";
        treeHelper(root, currPath, result);
        return result;
        
    }
};