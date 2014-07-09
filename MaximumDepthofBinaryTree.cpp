/**
    Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
**/
class Solution {
public:
    int depth(TreeNode* root, int distance) {
        if (!root)
            return distance;
            
        int L = depth(root->left, distance + 1);
        int R = depth(root->right, distance + 1);
        if (L > R)
            return L;
        return R;
    }
    
    int maxDepth(TreeNode *root) {
       return  depth(root, 0);
    }
};