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
    
    void inorderTraversalIterative(TreeNode* root, vector<int>& path) {
        if (!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode *prev = NULL, *current = NULL;
        
        while (!s.empty()) {
            current = s.top();
            if(!prev || prev->left == current || prev->right == current) {
                if (current->left) {
                    s.push(current->left);
                }
                else if (current->right) {
                    path.push_back(current->val);
                    if (current->right)
                        s.push(current->right);
                }
                else {
                    path.push_back(current->val);
                    s.pop();
                }
            }
            else if (current->left == prev) {
                path.push_back(current->val);
                if (current->right)
                    s.push(current->right);
                else
                    s.pop();
            }
            else if (current->right == prev){
                s.pop();
            }
            prev = current;
        }
        return;
    }    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorderPath;
        //inorder(root, inorderPath);
        inorderTraversalIterative(root, inorderPath);
        return inorderPath;
    }
};