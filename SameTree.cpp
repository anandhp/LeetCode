/**
    Given two binary trees, write a function to check if they are equal or not.
    
    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

**/
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};