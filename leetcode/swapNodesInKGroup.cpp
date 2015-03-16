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
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode*> s;
        ListNode* start = head;
        for(int i = 0; i < k; i++) {
            if(start == NULL)
                return head;
            s.push(start);
            start = start->next;
        }
        ListNode* subres = reverseKGroup(start, k);
        ListNode* res = s.top();
        s.pop();
        ListNode* prev = res;
        while(!s.empty()) {
            ListNode* next = s.top();
            s.pop();
            prev->next = next;
            prev = prev->next;
        }
        prev->next = subres;
        return res;
    }
};
