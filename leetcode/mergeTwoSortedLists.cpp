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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* start = NULL;
        ListNode* prev = NULL;
        while(!(l1 == NULL && l2 == NULL)) {
            if(l1 == NULL) {
                if(start == NULL) {
                    start = l2;
                    prev = start;
                    l2 = l2->next;
                } else {
                    prev->next = l2;
                    prev = prev->next;
                    l2 = l2->next;
                }
            } else if(l2 == NULL) {
                if(start == NULL) {
                    start = l1;
                    prev = start;
                    l1 = l1->next;
                } else {
                    prev->next = l1;
                    prev = prev->next;
                    l1 = l1->next;
                }
            } else {
                if(l1->val < l2->val) {
                    if(start == NULL) {
                        start = l1;
                        prev = start;
                        l1 = l1->next;
                    } else {
                        prev->next = l1;
                        prev = prev->next;
                        l1 = l1->next;
                    }
                } else {
                    if(start == NULL) {
                        start = l2;
                        prev = start;
                        l2 = l2->next;
                    } else {
                        prev->next = l2;
                        prev = prev->next;
                        l2 = l2->next;
                    }
                }
            }
        }
        if(prev != NULL)
            prev->next = NULL;
        return start;
    }
};
