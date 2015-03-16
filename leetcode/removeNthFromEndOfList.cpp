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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int count = 0;
        ListNode* copy = head;
        while(copy != NULL) {
            count++;
            copy = copy->next;
        }
        int index = count - n;
        if(index < 0 || index >= count)
            return head;
        if(index == 0)
            return head->next;
        index--;
        copy = head;
        while(index--) {
            copy = copy->next;
        }
        ListNode* rm = copy->next;
        ListNode* ne = rm->next;
        copy->next = ne;
        return head;
    }
};
