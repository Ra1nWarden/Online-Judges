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
    vector<TreeNode*> solve(vector<TreeNode*> v, vector<vector<int> >& ans) {
        vector<int> row;
        vector<TreeNode*> res;
        for(int i = 0; i < v.size(); i++) {
            row.push_back(v[i]->val);
            if(v[i]->left != NULL)
                res.push_back(v[i]->left);
            if(v[i]->right != NULL)
                res.push_back(v[i]->right);
        }
        ans.push_back(row);
        return res;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> v;
        if(root != NULL)
            v.push_back(root);
        vector<vector<int> > ans;
        while(!v.empty()) {
            v = solve(v, ans);
        }
        return ans;
    }
};
