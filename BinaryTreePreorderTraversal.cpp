/**
*   Given a binary tree, return the preorder traversal of its nodes' values.
*
*   For example:
*   Given binary tree {1,#,2,3},
*       1
*        \
*         2
*        /
*       3
*   return [1,2,3].
*
*   Note: Recursive solution is trivial, could you do it iteratively?
**/

class Solution {
public:
    void preorderTraversal(TreeNode* root, vector<int>& path) {
        if (!root)
            return;
        path.push_back(root->val);
        preorderTraversal(root->left, path);
        preorderTraversal(root->right, path);
        
    }
    
    void preorderTraversalIterative(TreeNode* root, vector<int>& path) {
        if (!root)
            return;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            path.push_back(node->val);
            nodeStack.pop();
            if (node->right)
                 nodeStack.push(node->right);
            if (node->left)
                 nodeStack.push(node->left);
        }
    }
        
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> path;
        preorderTraversal(root, path);
        return path;
    }
};
