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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* sub = swapPairs(head->next->next);
        ListNode* res = head->next;
        res->next = head;
        head->next = sub;
        return res;
    }
};
