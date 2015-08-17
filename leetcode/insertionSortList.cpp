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
    ListNode* insert(ListNode* node, ListNode* head) {
        if(head == NULL) {
            node->next = NULL;
            return node;
        }
        ListNode* ans = head;
        ListNode* prev = NULL;
        while(head != NULL) {
            if(head->val > node->val) {
                if(prev == NULL) {
                    node->next = head;
                    return node;
                } else {
                    prev->next = node;
                    node->next = head;
                    return ans;
                }
            }
            prev = head;
            head = head->next;
        }
        prev->next = node;
        node->next = NULL;
        return ans;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* sorted = insertionSortList(head->next);
        return insert(head, sorted);
    }
};
