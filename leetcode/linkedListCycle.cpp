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
    bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        bool isCycle = false;
        while(first != NULL && second != NULL) {
            first = first->next;
            second = second->next;
            if(second == NULL)
                return false;
            second = second->next;
            if(second == NULL || first == NULL)
                return false;
            if(first == second) {
                isCycle = true;
                break;
            }
        }
        return isCycle;
    }
};
