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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        while(prev) {
            if(prev->next == NULL)
                break;
            if(prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};
