/**
    Follow up for problem "Populating Next Right Pointers in Each Node".
    
    What if the given tree could be any binary tree? Would your previous solution still work?
    
    Note:
    
    You may only use constant extra space.
    For example,
    Given the following binary tree,
             1
           /  \
          2    3
         / \    \
        4   5    7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \    \
        4-> 5 -> 7 -> NULL

**/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<TreeLinkNode*> q;
        int parents = 1, children = 0;
        q.push(root);
        while(!q.empty()) {
            TreeLinkNode* node = q.front();
            q.pop();
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
                node->next = NULL;
            } else {
                node->next = q.front();
            }
        }
        
    }
};