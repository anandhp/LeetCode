/**

    Given a singly linked list L: L0->L1->…->Ln-1->Ln,
    reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->…
    
    You must do this in-place without altering the nodes' values.
    
    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.

**/

class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode*> nodes;
        ListNode* index = head;
        while(index) {
            nodes.push_back(index);
            index = index->next;
        }
        int i = 0, j = nodes.size() - 1;
        index = NULL;
        while(i <= j) {
            if(index)
                index->next = nodes[i];
            index = nodes[i];
            if (i == j)
                break;
            index->next = nodes[j];
            index = nodes[j];
            i++, j--;
        }
        if (index)
            index->next = NULL;
    }
};