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
    TreeNode* helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if(ps == pe || is == ie)
            return NULL;
        TreeNode* ans = new TreeNode(preorder[ps]);
        int i = is;
        for(; i < ie; i++) {
            if(inorder[i] == preorder[ps])
                break;
        }
        ans->left = helper(preorder, ps+1, ps+(i-is)+1, inorder, is, i);
        ans->right = helper(preorder, ps+(i-is)+1, pe, inorder, i+1, ie);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
