/**
*   Given a linked list, remove the nth node from the end of list and return its head.
*
*   For example,
*
*   Given linked list: 1->2->3->4->5, and n = 2.
*
*   After removing the second node from the end, the linked list becomes 1->2->3->5.
*   
*   Note:
*   Given n will always be valid.
*   Try to do this in one pass.
*
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* l1 = head;
        ListNode* l2 = head;
        
        while (l1 != 0 && n > 0) {
            l1 = l1->next;
            --n;
        }
        
        if (l1 == 0 && n == 0) {
            ListNode* delNode = head;
            head = head->next;
            return head;
        }
        else if (l1 == 0 && n > 0)
            return head;
        
        while (l1->next != 0) {
            l1= l1->next;
            l2 = l2->next;
        }
        
        ListNode* delNode = l2->next;
        l2->next = delNode->next;
        delete delNode;
        
        return head;    
    }
};