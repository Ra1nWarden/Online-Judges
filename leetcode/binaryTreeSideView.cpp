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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> v;
        if(root != NULL)
            v.push_back(root);
        while(!v.empty()) {
            ans.push_back(v.back()->val);
            vector<TreeNode*> vv;
            for(int i = 0; i < v.size(); i++) {
                if(v[i]->left != NULL)
                    vv.push_back(v[i]->left);
                if(v[i]->right != NULL)
                    vv.push_back(v[i]->right);
            }
            v = vv;
        }
        return ans;
    }
};
