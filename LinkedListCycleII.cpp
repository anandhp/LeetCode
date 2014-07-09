/**
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    
    Follow up:
    Can you solve it without using extra space?
    
**/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
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
};