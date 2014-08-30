/**
*   Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
**/

class Solution {
public:
    TreeNode *sortedListToBST2(ListNode *head) {
        if (!head)
            return NULL;
            
        if (!head->next)
            return new TreeNode(head->val);

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* n = slow;
        prev->next= NULL;
        
        TreeNode* root = new TreeNode(n->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(n->next);
        
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return NULL;
            
        int length = listLength(head);
        return listToBST(head, 0, length - 1);
    }

private:    
    int listLength(ListNode *head){
        int length = 0;
        while (head) {
            head= head->next;
            length += 1;
        }
        return length;
    }
    
    TreeNode *listToBST(ListNode*& head, int start, int end) {
        if (end < start)
            return NULL;
        
        TreeNode *left = listToBST(head, start, (end + start) / 2 - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = listToBST(head, (end + start) / 2 + 1, end);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};