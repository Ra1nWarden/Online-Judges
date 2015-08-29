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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head->next;
        }
        ListNode* ans = s.top();
        s.pop();
        ListNode* prev = ans;
        while(!s.empty()) {
            prev->next = s.top();
            s.pop();
            prev = prev->next;
        }
        prev->next = NULL;
        return ans;
    }
};
