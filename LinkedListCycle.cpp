/**
*   Given a linked list, determine if it has a cycle in it.
*
*   Follow up:
*   Can you solve it without using extra space?
*
**/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == 0)
            return false;
            
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while (fast && slow && fast != slow) {
            if (fast->next == 0)
                break;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast != slow)
            return false;
        return true;
    }
};