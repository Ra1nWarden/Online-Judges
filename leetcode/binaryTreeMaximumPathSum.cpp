/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int helper(TreeNode* root, bool side);

class Solution {
private:
    map<TreeNode*, int> tm, fm;
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        else
            return max(helper(root, true), helper(root, false));
    }
    int helper(TreeNode* root, bool side) {
        if(root == NULL)
            return 0;
        if(side) {
            if(tm.count(root))
                return tm[root];
            return tm[root] = root->val + max(0, max(helper(root->left, true), helper(root->right, true)));
        } else {
            if(fm.count(root))
                return fm[root];
            if(root->left != NULL && root->right != NULL) {
                int sub_ans = max(maxPathSum(root->left), maxPathSum(root->right));
                return fm[root] = max(sub_ans, helper(root->left, true) + helper(root->right, true) + root->val);
            } else if(root->left != NULL) {
                return fm[root] = maxPathSum(root->left);
            } else if(root->right != NULL) {
                return fm[root] = maxPathSum(root->right);
            }
        }
    }
};
