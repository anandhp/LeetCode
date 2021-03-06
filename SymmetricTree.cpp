/**
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
    
    For example, this binary tree is symmetric:
    
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    But the following is not:
        1
       / \
      2   2
       \   \
       3    3

**/

class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (left && right && left->val == right->val) {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};