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
       
    void postorderTraversalIterative(TreeNode* root, vector<int>& path) {
        if (!root)
            return;

        TreeNode* node = NULL, *prev = NULL;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            node = nodeStack.top();
            if (!prev || prev->left == node || prev->right == node) {
                if (node->left)
                    nodeStack.push(node->left);
                else if(node->right)
                    nodeStack.push(node->right);
                else { 
                    path.push_back(node->val);
                    nodeStack.pop();
                }    
            } else if (node->left == prev){
                if (node->right)
                    nodeStack.push(node->right);
                else { 
                    path.push_back(node->val);
                    nodeStack.pop();
                }
            }
            else if (node->right == prev) {
                path.push_back(node->val);
                nodeStack.pop();
            }
            prev = node;
        }
        return;
        
    }    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> path;
        postorderTraversal(root, path);
        return path;
    }
};