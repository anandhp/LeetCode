/**
*   Given preorder and inorder traversal of a tree, construct the binary tree.
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
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int &current) {
        if (end < start)
            return NULL;
        
        int index = find(inorder, start, end, preorder[current]);
        if (index == -1)
            return NULL;

        TreeNode *root = new TreeNode(preorder[current]);
        current++;
        root->left = buildTree(preorder, inorder, start, index - 1, current);
        root->right = buildTree(preorder, inorder, index + 1, end, current);
        
        return root;
    } 
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() == 0 || preorder.size() == 0)
            return NULL;
            
        int current = 0;
        return buildTree(preorder, inorder, 0, inorder.size() - 1, current);
    }
};