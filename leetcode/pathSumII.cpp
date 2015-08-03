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
    void solve(TreeNode* root, int sum, vector<int> v, vector<vector<int> >& ans) {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val) {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        if(root->left != NULL) {
            vector<int> vcpy = v;
            vcpy.push_back(root->val);
            solve(root->left, sum - root->val, vcpy, ans);
        }
        if(root->right != NULL) {
            vector<int> vcpy = v;
            vcpy.push_back(root->val);
            solve(root->right, sum - root->val, vcpy, ans);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> v;
        solve(root, sum, v, ans);
        return ans;
    }
};
