/**
*   Write a program to find the node at which the intersection of two singly linked lists begins.
*
*
*   For example, the following two linked lists:
*   
*   A:      a1 - a2
*                  \
*                   c1 -> c2 - c3
*                  /             
*   B: b1 - b2 - b3
*
*   begin to intersect at node c1.
*
*
*   Notes:
*
*   - If the two linked lists have no intersection at all, return null.
*   - The linked lists must retain their original structure after the function returns.
*   - You may assume there are no cycles anywhere in the entire linked structure.
*   - Your code should preferably run in O(n) time and use only O(1) memory.
*
**/

class Solution {
public:
    int length(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
    ListNode* adjust(ListNode *head, int count) {
        while (count-- > 0)
            head = head->next;
        
        return head;    
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        
        headA = adjust(headA, lenA - lenB);
        headB = adjust(headB, lenB - lenA);
        
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};