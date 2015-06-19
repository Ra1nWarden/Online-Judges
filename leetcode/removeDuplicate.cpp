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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        ListNode* cur = ans;
        while(head != NULL) {
            ListNode* next = head->next;
            if(next != NULL) {
                if(cur->val != next->val) {
                    cur->next = next;
                    cur = next;
                }
            }
            head = next;
        }
        if(cur != NULL)
            cur->next = NULL;
        return ans;
    }
};
