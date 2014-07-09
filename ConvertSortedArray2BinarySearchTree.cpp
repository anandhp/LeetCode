/**
*   Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
**/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &num, int low, int high) {
        if (high < low)
            return NULL;
        
        int size = high - low + 1;
        int mid = low + size / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, low, mid - 1);
        root->right = sortedArrayToBST(num, mid + 1 , high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
};
