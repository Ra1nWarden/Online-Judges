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
    int totalNodes(TreeNode* root) {
        if(root == 0)
            return 0;
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = totalNodes(root->left);
        if(k <= leftCount) {
            return kthSmallest(root->left, k);
        } else if(k > leftCount + 1) {
            return kthSmallest(root->right, k - leftCount - 1);
        } else {
            return root->val;
        }
    }
};
