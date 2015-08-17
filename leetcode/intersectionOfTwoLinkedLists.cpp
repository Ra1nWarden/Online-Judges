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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_length = 0, b_length = 0;
        ListNode* itr = headA;
        while(itr != NULL) {
            itr = itr->next;
            a_length++;
        }
        itr = headB;
        while(itr != NULL) {
            itr = itr->next;
            b_length++;
        }
        while(a_length != b_length) {
            if(a_length < b_length) {
                headB = headB->next;
                b_length--;
            } else if(b_length < a_length) {
                headA = headA->next;
                a_length--;
            }
        }
        while(headA != NULL && headB != NULL) {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
