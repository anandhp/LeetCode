/**
    Given a binary tree, find the maximum path sum.
    
    The path may start and end at any node in the tree.
    
    For example:
    Given the below binary tree,
    
           1
          / \
         2   3
    
    Return 6.

**/

class Solution {
public:
    int maxNum(int a, int b) {
        if (a > b)
            return a;
        return b;
    }
    
    int maxPathSum(TreeNode* root, int& maxSum) {
        if (!root) {
            return 0;
        }    
        int leftSum = maxPathSum(root->left, maxSum);
        int rightSum = maxPathSum(root->right, maxSum);
        
        int sum = maxNum(root->val, maxNum(root->val + leftSum, root->val + rightSum));
        maxSum = maxNum(maxSum, maxNum(sum, root->val + leftSum + rightSum));
        return sum;
    }
    
    int maxPathSum(TreeNode *root) {
        if (!root)
            return 0;
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};