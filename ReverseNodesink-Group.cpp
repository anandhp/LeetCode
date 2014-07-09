/**
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
    
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
    
    You may not alter the values in the nodes, only nodes itself may be changed.
    
    Only constant memory is allowed.
    
    For example,
    Given this linked list: 1->2->3->4->5
    
    For k = 2, you should return: 2->1->4->3->5
    
    For k = 3, you should return: 3->2->1->4->5
    
**/

class Solution {
public:
    ListNode *reverseKGroup2(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
            
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        ListNode* p1 = head, *p2 = head;
        int index = 0;
        
        while (1) {
            for(; p2 && index < k; p2= p2->next, index++);
            if (!p2 && index < k) {
                tail->next = p1;
                break;
            }
            ListNode* curTail = tail;
            tail = p1;
            while (p1 != p2) {
                ListNode* temp = p1;
                p1 = p1->next;
                temp->next = curTail->next;
                curTail->next = temp;
            }
            index = 0;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
        
        ListNode *current = head;
        ListNode *prev = NULL, *next = NULL;
        int counter = 0;
        
        while (current && counter < k) {
            current = current->next;
            counter++;
        }
        
        if (!current && counter < k)
            return head;
        
        current = head;
        counter = 0;
        
        while (current && counter < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            counter++;
        }
        if (next) {
            head->next = reverseKGroup(next, k);
        }
        
        return prev;
    }
};