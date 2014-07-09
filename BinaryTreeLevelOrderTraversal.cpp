/**
    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
    
    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its level order traversal as:
    [
      [3],
      [9,20],
      [15,7]
    ]
    
**/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> levels;
        if (!root)
            return levels;
            
        vector<int> level;
        queue<TreeNode*> q;
        int parents = 1, children = 0;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            parents--;
            level.push_back(node->val);

            if (node->left) {
                q.push(node->left);
                children++;
            }
            if (node->right) {
                q.push(node->right);
                children++;
            }
            if (parents == 0) {
                levels.push_back(level);
                level.erase(level.begin(), level.end());
                parents = children;
                children = 0;
            }            
        }
        return levels;
    }
};