/**
*   Merge two sorted linked lists and return it as a new list. 
*   The new list should be made by splicing together the nodes of the first two lists.
*
**/

class Solution {
public:
    ListNode* getNextNode(ListNode*& n1, ListNode*& n2) {
        ListNode* ret = NULL;
        if (n1 && n2) {
            if (n1->val < n2->val) {
                ret = n1;
                n1 = next(n1);
            }
            else {
                ret =  n2;
                n2 = next(n2);
            }
        } else if (n1) {
            ret =  n1;
            n1 = next(n1);
        } else if (n2) {
            ret = n2;
            n2 = next(n2);
        }
        return ret;
    }
    
    ListNode* next(ListNode* n) {
        if (n)
            return n->next;
        return n;
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* l = NULL;
        ListNode* current = NULL;
 
        l = current = getNextNode(l1, l2);

        while (l1 && l2) {
            current->next = getNextNode(l1, l2);
            current = next(current);
        }
        
         while (l1) {
             current->next = l1;
             l1 = next(l1);
             current = next(current);
         }
         while (l2) {
             current->next = l2;
             l2 = next(l2);
             current = next(current);             
         }
         
         return l;
    }
};