/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* start = NULL;
        ListNode* prev = start;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            if(start == NULL) {
                start = new ListNode(sum % 10);
                prev = start;
            } else {
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }
        }
        if(carry != 0)
            prev->next = new ListNode(carry);
        return start;
    }
};
