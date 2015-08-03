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
    vector<TreeNode*> solve(vector<TreeNode*> nodes, vector<vector<int> >& ans) {
        vector<TreeNode*> ret;
        vector<int> row;
        for(int i = 0; i < nodes.size(); i++) {
            row.push_back(nodes[i]->val);
            if(nodes[i]->left != NULL)
                ret.push_back(nodes[i]->left);
            if(nodes[i]->right != NULL)
                ret.push_back(nodes[i]->right);
        }
        ans.push_back(row);
        return ret;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        while(!nodes.empty()) {
            nodes = solve(nodes, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
