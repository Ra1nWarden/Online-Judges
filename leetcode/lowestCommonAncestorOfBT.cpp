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
    bool generatePath(TreeNode* cur, TreeNode* target, vector<TreeNode*>& v) {
        if(cur == NULL)
            return false;
        v.push_back(cur);
        if(cur == target)
            return true;
        if(generatePath(cur->left, target, v))
            return true;
        if(generatePath(cur->right, target, v))
            return true;
        v.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv, qv;
        if(!generatePath(root, p, pv) || !generatePath(root, q, qv))
            return NULL;
        TreeNode* ans = NULL;
        for(int i = 0; i < min(pv.size(), qv.size()); i++) {
            if(pv[i] != qv[i]) {
                break;
            }
            ans = pv[i];
        }
        return ans;
    }
};
