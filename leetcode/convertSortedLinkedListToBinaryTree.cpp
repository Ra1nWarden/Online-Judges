/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(ListNode* start, ListNode* end) {
        int n = 0;
        ListNode* itr = start;
        while(itr != end) {
            itr = itr->next;
            n++;
        }
        if(n == 0)
            return NULL;
        n /= 2;
        itr = start;
        while(n--) {
            itr = itr->next;
        }
        TreeNode* ans = new TreeNode(itr->val);
        ans->left = helper(start, itr);
        ans->right = helper(itr->next, end);
        return ans;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }
};
