/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
typedef pair<ListNode*, int> LI;
 
class CompareListNode {
public:
    bool operator()(LI& one, LI& two) {
        if(one.first == NULL)
            return false;
        if(two.first == NULL)
            return true;
        return one.first->val > two.first->val;
    }
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* start = NULL;
        ListNode* prev = start;
        priority_queue<LI, vector<LI>, CompareListNode> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(make_pair(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }
        while(!pq.empty()) {
            LI next = pq.top();
            pq.pop();
            if(next.first == NULL)
                continue;
            if(lists[next.second] != NULL) {
                pq.push(make_pair(lists[next.second], next.second));
                lists[next.second] = lists[next.second]->next;
            }
            if(start == NULL) {
                start = next.first;
                prev = start;
                prev->next = NULL;
            } else {
                prev->next = next.first;
                prev = prev->next;
                prev->next = NULL;
            }
        }
        return start;
    }
};
