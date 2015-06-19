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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* cur = NULL;
        stack<ListNode*> s;
        while(head != NULL) {
            if(!s.empty()) {
                if(s.top()->val != head->val) {
                    if(s.size() == 1) {
                        if(ans == NULL) {
                            ans = s.top();
                            ans->next = NULL;
                            cur = ans;
                        } else {
                            cur->next = s.top();
                            cur = cur->next;
                            cur->next = NULL;
                        }
                    }
                    while(!s.empty())
                        s.pop();
                }
            }
            s.push(head);
            head = head->next;
        }
        if(s.size() == 1) {
            if(cur != NULL) {
                cur->next = s.top();
                cur->next->next = NULL;
            } else {
                ans = s.top();
                ans->next = NULL;
            }
        }
        return ans;
    }
};
