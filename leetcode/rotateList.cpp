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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* itr = head;
        while(itr != NULL) {
            itr = itr->next;
            n++;
        }
        if(n == 0)
            return head;
        int shift = n - k % n;
        shift--;
        if(shift == n - 1)
            return head;
        itr = head;
        while(shift--) {
            itr = itr->next;
        }
        ListNode* ans = itr->next;
        itr->next = NULL;
        itr = ans;
        while(itr->next != NULL)
            itr = itr->next;
        itr->next = head;
        return ans;
    }
};
