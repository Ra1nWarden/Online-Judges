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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> q;
        ListNode* ans = NULL;
        ListNode* prev = NULL;
        while(head != NULL) {
            if(head->val < x) {
                if(prev == NULL) {
                    prev = head;
                    ans = head;
                } else {
                    prev->next = head;
                    prev = prev->next;
                }
            } else {
                if(prev != NULL) {
                    prev->next = NULL;
                }
                q.push(head);
            }
            head = head->next;
        }
        while(!q.empty()) {
            if(prev != NULL) {
                prev->next = q.front();
                prev = prev->next;
            } else {
                prev = q.front();
                ans = prev;
            }
            q.pop();
            prev->next = NULL;
        }
        return ans;
    }
};
