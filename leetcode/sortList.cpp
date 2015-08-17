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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* itr = NULL;
        ListNode* ans;
        while(a != NULL && b != NULL) {
            bool a_small = a->val < b->val;
            if(itr == NULL) {
                itr = a_small ? a : b;
                ans = itr;
            } else {
                itr->next = a_small ? a : b;
                itr = itr->next;
            }
            if(a_small)
                a = a->next;
            else
                b = b->next;
        }
        if(a != NULL)
            itr->next = a;
        else
            itr->next = b;
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode* itr = head;
        while(itr != NULL) {
            itr = itr->next;
            n++;
        }
        if(n <= 1)
            return head;
        itr = head;
        for(int i = 0; i < n / 2 - 1; i++) {
            itr = itr->next;
        }
        ListNode* next_head = itr->next;
        itr->next = NULL;
        ListNode* a = sortList(head);
        ListNode* b = sortList(next_head);
        return merge(a, b);
    }
};
