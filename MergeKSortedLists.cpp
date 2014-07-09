/**
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
**/

class Solution {
public:
    void adjustNode(ListNode*& node, ListNode*& next) {
        node->next = next;
        node = next;
        next = next->next;
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode* result = new ListNode(-1);
        ListNode* last = result;
        
        while (l1 && l2) {
            if (l1->val < l2->val)
                adjustNode(last, l1);
            else
                adjustNode(last, l2);
        }
        
        while (l1)
            adjustNode(last, l1);
        while (l2) 
            adjustNode(last, l2);

        last->next = NULL;
        last = result;
        result = result->next;
        delete last;
        return result;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* result = NULL;
        for (int i = 0; i < lists.size(); i++)
            result = mergeList(result, lists[i]);
        return result;
    }
};