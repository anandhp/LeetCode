/**
    Sort a linked list in O(n log n) time using constant space complexity.
**/

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* index = result;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                index->next = l1;
                l1= l1->next;
            } else {
                index->next = l2;
                l2= l2->next;
            }
            index = index->next;
        }
        
        while (l1) {
            index->next = l1;
            l1= l1->next;
            index = index->next;
        }
        while (l2) {
            index->next = l2;
            l2= l2->next;
            index = index->next;
        }
        index->next = NULL;
        index = result;
        result = result->next;
        delete index;
        return result;
    }
    
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(second);
        
        return merge(l1, l2);
    }
};