/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<RandomListNode*, RandomListNode*> m;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        if(m.count(head))
            return m[head];
        RandomListNode* ans = new RandomListNode(head->label);
        m[head] = ans;
        ans->next = copyRandomList(head->next);
        ans->random = copyRandomList(head->random);
        return ans;
    }
};
