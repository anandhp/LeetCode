/**
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* result = 0;
        ListNode* current = 0;
        int carry = 0;
        
        while(l1 != 0 & l2 != 0) {
            int resultVal = l1->val + l2->val + carry;
            carry = resultVal / 10;
            ListNode* node = new ListNode(resultVal % 10);
            
            if (result == 0) {
                result = node;
                current = result;
            }
            else {
                current->next = node;
                current = current->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1 != 0) {
            while(l1 != 0) {
                int resultVal = l1->val + carry;
                carry = resultVal / 10;
                ListNode* node = new ListNode(resultVal % 10);                
                if (result == 0) {
                    result = node;
                    current = result;
                }
                else {
                    current->next = node;
                    current = current->next;
                }
                l1 = l1->next;
            }
        }
        if (l2 != 0) {
            while(l2 != 0) {
                int resultVal = l2->val + carry;
                carry = resultVal / 10;
                ListNode* node = new ListNode(resultVal % 10);                
                if (result == 0) {
                    result = node;
                    current = result;
                }
                else {
                    current->next = node;
                    current = current->next;
                }
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);                
            if (result == 0) {
                result = node;
                current = result;
            }
            else {
                current->next = node;
                current = current->next;
            }               
        }
        return result;
    }
    
};