/**
*
*   Two elements of a binary search tree (BST) are swapped by mistake.
*    Recover the tree without changing its structure.
*
**/

class Solution {
public:
    void findError(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&previous) {
        if (!root)
            return;

        findError(root->left, first, second, previous);
                
        if(!previous)
            previous = root;
            
        else {
            if (previous->val > root->val) {
                if (!first)
                    first = previous;
                second = root;
            }
            previous = root;
        }
        
        findError(root->right, first, second, previous);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *first = NULL, *second = NULL, *previous = NULL;
        findError(root, first, second, previous);
        if (first && second) {
            swap(first->val, second->val); 
        }
    }
     
};