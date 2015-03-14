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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root != NULL)
            st.push(root);
        set<TreeNode*> expanded;
        while(!st.empty()) {
            TreeNode* next = st.top();
            st.pop();
            if(expanded.count(next) == 0) {
                st.push(next);
                if(next->right != NULL)
                    st.push(next->right);
                if(next->left != NULL)
                    st.push(next->left);
                expanded.insert(next);
            } else {
                result.push_back(next->val);
            }
        }
        return result;
    }
};
