/**
    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
    
    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
      [15,7],
      [9,20],
      [3]
    ]
**/

class Solution {
public:

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> levels;
        if (!root)
            return levels;
            
        queue<TreeNode*> q;
        q.push(root);
        int parents = 1, children = 0;
        vector<int> level;
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            parents--;
            
            if (node->left) {
                q.push(node->left);
                children++;
            }
            
            if (node->right) {
                q.push(node->right);
                children++;
            }
            
            if (parents == 0) {
                parents = children;
                children = 0;
                levels.insert(levels.begin(), level);
                level.clear();
            }
        }
        
        return levels;
    }
};