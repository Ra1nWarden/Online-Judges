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
    stack<TreeNode*> solve(stack<TreeNode*> v, vector<vector<int> >& ans, bool rev) {
        vector<int> row;
        stack<TreeNode*> res;
        while(!v.empty()) {
            TreeNode* node = v.top();
            v.pop();
            row.push_back(node->val);
            if(!rev) {
                if(node->left != NULL)
                    res.push(node->left);
                if(node->right != NULL)
                    res.push(node->right);
            } else {
                if(node->right != NULL)
                    res.push(node->right);
                if(node->left != NULL)
                    res.push(node->left);
            }
        }
        ans.push_back(row);
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> v;
        if(root != NULL)
            v.push(root);
        vector<vector<int> > ans;
        bool rev = false;
        while(!v.empty()) {
            v = solve(v, ans, rev);
            rev = !rev;
        }
        return ans;
    }
};
