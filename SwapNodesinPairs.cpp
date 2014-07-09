/**

    Given a linked list, swap every two adjacent nodes and return its head.
    
    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.
    
    Your algorithm should use only constant space. You may not modify the values in the 
    list, only nodes itself can be changed.

**/

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* node = head;
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        while (head) {
            if (!newHead) {
                if(head->next) {
                    ListNode* next  = head->next->next;
                    newHead = head->next;
                    newHead->next = head;
                    tail = newHead->next;
                    head =  next;
                }
                else 
                    return head;
            } else {
                if(head->next) {
                    ListNode* next  = head->next->next;
                    tail->next = head->next;
                    tail->next->next = head;
                    tail = head;
                    head = next;
                } else {
                    tail->next = head;
                    tail = head;
                    head = head->next;
                }
            }
        }
        if (tail)
            tail->next = NULL;
        return newHead;
    }
};