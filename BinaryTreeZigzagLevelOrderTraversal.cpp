/**
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
    
    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its zigzag level order traversal as:
    [
      [3],
      [20,9],
      [15,7]
    ]

**/

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> zigzagPath;
        if (!root)
            return zigzagPath;

        vector<int> level;
        deque<TreeNode*> q;
        int parents = 1, children = 0;
        bool forward = true;
        q.push_back(root);
        while(!q.empty()) {
            TreeNode* node = forward ? q.front() : q.back();
            forward ? q.pop_front() : q.pop_back();
            level.push_back(node->val);
            parents--;
            
            if (forward) {
                if (node->left) {
                    q.push_back(node->left);
                    children++;
                }
                if (node->right) {
                    q.push_back(node->right);
                    children++;
                }
            } else {
                if (node->right) {
                    q.push_front(node->right);
                    children++;
                }                
                if (node->left) {
                    q.push_front(node->left);
                    children++;
                }
            }
            if (parents == 0) {
                parents = children;
                children = 0;
                zigzagPath.push_back(level);
                level.erase(level.begin(), level.end());
                forward = !forward;                
            }

        }
    }
};