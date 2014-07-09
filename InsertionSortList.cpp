/**
    Sort a linked list using insertion sort.
**/

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return head;
            
        ListNode* i = head->next;
        while (i) {
            ListNode* j = head;
            while (j && j->next != i->next) {
                if (j->val > i->val) {
                    int temp = j->val;
                    j->val = i->val;
                    i->val = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
        return head;
    }
};