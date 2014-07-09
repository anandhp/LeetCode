/**
    Given a binary tree, find its minimum depth.
    
    The minimum depth is the number of nodes along the shortest path from the root node 
    down to the nearest leaf node.
    
**/
class Solution {
public:
    bool leaf(TreeNode* node) {
        return !node->left && !node->right;
    }
    
    int depth(TreeNode* root, int distance) {
        if (!root)
            return 0;
            
        if (leaf(root)) {
            return distance + 1;
        }
        
        int minDepthL = 0, minDepthR = 0;
        minDepthL = depth(root->left, distance + 1);
        minDepthR = depth(root->right, distance + 1);

        if (!root->left)
            return minDepthR;
        else if(!root->right)
            return minDepthL;
        else if (minDepthL < minDepthR)
            return minDepthL;
        return minDepthR;
        
    }
    
    int minDepth(TreeNode *root) {
            return depth(root, 0);
    }
};