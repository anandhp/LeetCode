/**
*   A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
*
*   Return a deep copy of the list.
**/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;
            
        RandomListNode* current = head;
        
        while (current) {
            RandomListNode* copy = new RandomListNode(current->label);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }
        
        current = head;
        
        while (current) {
            RandomListNode* copy = current->next;
            if (current->random)
                copy->random = current->random->next;
            current = copy->next;
        }
        
        current = head;
        RandomListNode* newList = current->next;

        while (current) {
            RandomListNode* copy = current->next;
            current->next = current->next->next;
            if (copy->next)
                copy->next = copy->next->next;
            current = current->next;
        }
        
        return newList;
    }
};