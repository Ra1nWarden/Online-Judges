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
    int helper(int sum, TreeNode* node) {
        if(node == NULL)
            return sum;
        int new_sum = sum * 10 + node->val;
        if(node->left != NULL && node->right != NULL)
            return helper(new_sum, node->left) + helper(new_sum, node->right);
        else if(node->left != NULL)
            return helper(new_sum, node->left);
        else if(node->right != NULL)
            return helper(new_sum, node->right);
        else
            return new_sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = helper(0, root);
        return ans;
    }
};
