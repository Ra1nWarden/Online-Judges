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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start >= end)
            return NULL;
        int mid = (start + end) >> 1;
        TreeNode* ans = new TreeNode(nums[mid]);
        ans->left = helper(nums, start, mid);
        ans->right = helper(nums, mid+1, end);
        return ans;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
