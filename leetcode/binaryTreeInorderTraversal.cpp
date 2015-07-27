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
    void update(TreeNode* cur, vector<int>& v) {
        if(cur == NULL)
            return;
        update(cur->left, v);
        v.push_back(cur->val);
        update(cur->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        update(root, ans);
        return ans;
    }
};
