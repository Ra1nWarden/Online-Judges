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
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        bool isCycle = false;
        while(first != NULL && second != NULL) {
            first = first->next;
            second = second->next;
            if(second == NULL)
                return NULL;
            second = second->next;
            if(second == NULL || first == NULL)
                return NULL;
            if(first == second) {
                isCycle = true;
                break;
            }
        }
        if(!isCycle)
            return NULL;
        first = head;
        while(first != second) {
            first = first->next;
            second = second->next;
            if(first == NULL || second == NULL)
                return NULL;
        }
        return first;
    }
};
