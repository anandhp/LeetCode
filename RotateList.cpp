/**
*   Given a list, rotate the list to the right by k places, where k is non-negative.
*
*   For example:
*   Given 1->2->3->4->5->NULL and k = 2,
*   return 4->5->1->2->3->NULL.
**/

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
            
        ListNode* l = head;
        ListNode* p = head;
        
        while (k-- > 0) {
            l = l->next;
            if (!l)
                l = head;
        }
        
        if (!l)
            return head;
            
        while (l->next) {
            l = l->next;
            p = p->next;
        }

        l->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};