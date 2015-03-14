/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root != NULL)
            st.push(root);
        while(!st.empty()) {
            TreeNode* next = st.top();
            st.pop();
            result.push_back(next->val);
            if(next->right != NULL)
                st.push(next->right);
            if(next->left != NULL)
                st.push(next->left);
        }
        return result;
    }
};
