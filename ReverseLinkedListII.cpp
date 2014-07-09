/**
    Reverse a linked list from position m to n. Do it in-place and in one-pass.
    
    For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    
    return 1->4->3->2->5->NULL.
    
    Note:
    
    Given m, n satisfy the following condition:
    1 = m = n = length of list.
    
**/

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode d(-1);
        d.next = head;
        
        ListNode* l = &d;
        int index = 1;
        
        while (l && index < m) {
            l = l->next;
            index++;
        }
        
        if (!l)
            return d.next;
            
        ListNode* start = l;
        l = l->next;
        
        while(l && index < n) {
            ListNode* temp = l->next;
            l->next = l->next->next;
            temp->next = start->next;
            start->next = temp;
            index++;
        }
        return d.next;
    }
};