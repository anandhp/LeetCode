/**
    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
    
    For example:
    Given the below binary tree and sum = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1
    return
    [
       [5,4,11,2],
       [5,8,4,5]
    ]

**/

class Solution {
public:
    bool leaf(TreeNode* node) {
        if (!node->left && !node->right)
            return true;
        return false;
    }
    void findPaths(TreeNode* root,  int sum, vector<vector<int>>& paths, vector<int> path) {
        if (leaf(root)) {
            if (sum == root->val) {
                path.push_back(root->val);
                paths.push_back(path);
            }
            return;
        }
        
        path.push_back(root->val);
    
        if (root->left)
            findPaths(root->left, sum - root->val, paths, path);
        
        if (root->right)
            findPaths(root->right, sum - root->val, paths, path);
        return;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
    
        if (root)
            findPaths(root, sum, paths, path);
        return paths;
    }
};
