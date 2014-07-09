/**
*   Given a binary tree, return the postorder traversal of its nodes' values.
*
*   For example:
*   Given binary tree {1,#,2,3},
*       1
*        \
*         2
*        /
*       3
*   return [3,2,1].
*
*   Note: Recursive solution is trivial, could you do it iteratively?
**/

class Solution {
public:
    void postorderTraversal(TreeNode* root, vector<int>& path) {
        if (!root)
            return;
        postorderTraversal(root->left, path);
        postorderTraversal(root->right, path);
        path.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> path;
        postorderTraversal(root, path);
        return path;
    }
};