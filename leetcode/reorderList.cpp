/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int count(ListNode *node) {
        int result = 0;
        while(node != NULL) {
            node = node->next;
            result++;
        }
        return result;
    }
public:
    void reorderList(ListNode *head) {
        int size = count(head);
        int half = size / 2;
        ListNode* start = head;
        stack<ListNode*> st;
        for(int i = 1; i <= size; i++) {
            if(size - i < half)
                st.push(start);
            start = start->next;
        }
        ListNode* first = head;
        for(int i = 1; i <= half; i++) {
            ListNode* second = NULL;
            if(i * 2 != size)
                second = first->next;
            ListNode* insert = st.top();
            st.pop();
            first->next = insert;
            insert->next = second;
            first = second;
        }
        if(half * 2 < size)
            first->next = NULL;
            
    }
};
