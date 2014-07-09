/**

    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
    
    For example,

    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.

**/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        map<int, ListNode*> nodeMap;
        ListNode* node = head;
        while (node) {
            if (nodeMap.find(node->val) == nodeMap.end()) {
                ListNode* temp = node;
                node = node->next;
                nodeMap[temp->val] = temp;
                nodeMap[temp->val]->next = NULL;
            } else {
                ListNode* temp = node;
                node = node->next;
                temp->next = nodeMap[temp->val];
                nodeMap[temp->val] = temp;
            }
        }
        head = NULL;
        for(map<int, ListNode*>::reverse_iterator it = nodeMap.rbegin(); it != nodeMap.rend(); ++it)
            if (!it->second->next)  {
                it->second->next = head;
                head = it->second;
            }
        return head;
    }

};