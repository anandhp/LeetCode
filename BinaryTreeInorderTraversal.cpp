/**
    Given a binary tree, return the inorder traversal of its nodes' values.
    
    For example:
    Given binary tree {1,#,2,3},
       1
        \
         2
        /
       3
    return [1,3,2].
    
    Note: Recursive solution is trivial, could you do it iteratively?
    
**/

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& path) {
        if (!root)
            return;
            
        inorder(root->left, path);
        path.push_back(root->val);
        inorder(root->right, path);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorderPath;
        inorder(root, inorderPath);
        return inorderPath;
    }
};