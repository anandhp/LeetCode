/**
    Given a binary tree, determine if it is height-balanced.
    
    For this problem, a height-balanced binary tree is defined as a binary tree in 
    which the depth of the two subtrees of every node never differ by more than 1.
    
**/

class Solution {
public:
    bool  isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        int lh = 0, rh = 0;
        bool leftBalanced = isBalanced(root->left, lh);
        bool rightBalanced = isBalanced(root->right, rh);

        height = (lh > rh ? lh : rh) + 1;
        if ((lh - rh > 1) || (rh - lh) > 1)
            return false;
        
        return leftBalanced && rightBalanced;
        
    }
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        int height = 0;
        return isBalanced(root, height);
    }
};