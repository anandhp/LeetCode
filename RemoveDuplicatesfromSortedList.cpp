/**
*   Given a sorted linked list, delete all duplicates such that each element appear only once.
*
*   For example,
*   Given 1->1->2, return 1->2.
*   Given 1->1->2->3->3, return 1->2->3.
*
**/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
            
        ListNode* current = head->next;
        ListNode* l = head;
        
        while (current != NULL) {
            if (l->val != current->val) {
                l->next = current;
                l = l->next;
            }
            current = current->next;
        }
        
        l->next = NULL;
        return head;
    }
};