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
    const int inf = 2000000000;
    bool check(TreeNode* node, bool inflow, bool infup, int lower, int upper) {
        if(node == NULL)
            return true;
        if((node->val > lower || inflow) && (node->val < upper || infup)) {
            return check(node->left, inflow, false, lower, node->val) && check(node->right, false, infup, node->val, upper);
        } else {
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, true, true, -inf, inf);
    }
};
