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
public:
    int countNodes(TreeNode* root) {
        int left = 0, right = 0;
        TreeNode* itr = root;
        while(itr != NULL) {
            left++;
            itr = itr->left;
        }
        itr = root;
        while(itr != NULL) {
            right++;
            itr = itr->right;
        }
        if(left == right) {
            return (1 << left) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
