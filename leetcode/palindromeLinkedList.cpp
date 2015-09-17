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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second_half = slow->next;
        slow->next = NULL;
        ListNode dummy(-1);
        ListNode* prev = NULL;
        dummy.next = second_half;
        ListNode* cur = second_half;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            dummy.next = cur;
            cur = next;
        }
        ListNode* i = head;
        ListNode* j = dummy.next;
        while(i && j) {
            if(i->val != j->val)
                return false;
            i = i->next;
            j = j->next;
        }
        return true;
    }
};
