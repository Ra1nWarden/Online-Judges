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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ans = head;
        ListNode* running = head;
        ListNode* prev = NULL;
        int i = 1;
        for(; i < m; i++) {
            prev = running;
            running = running->next;
        }
        stack<ListNode*> nodes;
        ListNode* after = NULL;
        for(; i <= n; i++) {
            nodes.push(running);
            running = running->next;
            after = running;
        }
        if(prev == NULL) {
            ans = nodes.top();
            nodes.pop();
            prev = ans;
        }
        while(!nodes.empty()) {
            ListNode* nextNode = nodes.top();
            nodes.pop();
            prev->next = nextNode;
            prev = nextNode;
        }
        prev->next = after;
        return ans;
    }
};
