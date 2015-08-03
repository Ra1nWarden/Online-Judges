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
    bool helper(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL) {
            return true;
        } else if(a != NULL && b != NULL) {
            return a->val == b->val && helper(a->left, b->right) && helper(a->right, b->left);
        } else {
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return helper(root->left, root->right);
    }
};
