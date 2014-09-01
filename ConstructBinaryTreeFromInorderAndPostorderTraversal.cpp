/**
*   Given inorder and postorder traversal of a tree, construct the binary tree.
*
*   Note:
*   You may assume that duplicates do not exist in the tree.
*
**/

class Solution {
public:
    int find(vector<int> &inorder, int start, int end, int value) {
        for (int i = start; i <= end; i++)
            if (inorder[i] == value)
                return i;
        return -1;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &current) {
        if (end < start)
            return NULL;
        
        int index = find(inorder, start, end, postorder[current]);
        if (index == -1)
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[current--]);
        root->right = buildTree(inorder, postorder, index + 1, end, current);
        root->left = buildTree(inorder, postorder, start, index - 1, current);
        return root;   
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int current = postorder.size() - 1;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, current);
    }
};