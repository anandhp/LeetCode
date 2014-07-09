/**
    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    
    You should preserve the original relative order of the nodes in each of the two partitions.
    
    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.

**/

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* node = head;
        ListNode* n1 = new ListNode(-1);
        ListNode* n2 = new ListNode(-1);
        ListNode *nh1 = n1, *nh2 = n2;
        while (node) {
            if (node->val < x) {
                n1->next = node;
                n1= node;
            }
            else {
                n2->next = node;
                n2 = node;
            }
            node = node->next;
        }
        n1->next = nh2->next;
        n2->next = NULL;
        delete nh2;
        n1 = nh1;
        nh1 = nh1->next;
        delete n1;
        return nh1;
    }
};