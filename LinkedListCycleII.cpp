/**
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    
    Follow up:
    Can you solve it without using extra space?
    
**/

class Solution {
public:
    ListNode *detectCycleEx(ListNode *head) {
        set<ListNode*> nodeMap;
        ListNode* n = head;
        while (n) {
            if(nodeMap.find(n) != nodeMap.end())
                return n;
            nodeMap.insert(n);
            n = n->next;
        }
        
        return NULL;
    }
    //Better solution without using space
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
            
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        if (slow != fast)
            return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }    
};