/**
    Given a binary tree, flatten it to a linked list in-place.
    
    For example,
    Given
    
             1
            / \
           2   5
          / \   \
         3   4   6
    The flattened tree should look like:
       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
**/

class Solution {
public:
    void flatten(TreeNode*& last, TreeNode* node) {
        if (!node)
            return;

        last->right = node;
        last = node;
        flattenList(node, last);
    }
    
    void flattenList(TreeNode* root, TreeNode*& last) {
        if (!root)
            return;
            
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        
        flatten(last, left);
        flatten(last, right);
    }
    
    void flatten(TreeNode *root) {
        if(!root)
            return;
        flattenList(root, root);
    }
};