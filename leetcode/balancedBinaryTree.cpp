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
    bool helper(TreeNode* root, int& maxHeight) {
        if(root == NULL) {
            maxHeight = 0;
            return true;
        }
        int lheight, rheight;
        if(helper(root->left, lheight) && helper(root->right, rheight)) {
            maxHeight = max(lheight, rheight) + 1;
            return abs(lheight - rheight) <= 1;
        } else {
            return false;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return helper(root, height);
    }
};
