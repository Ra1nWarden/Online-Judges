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
    TreeNode* helper(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if(ps == pe || is == ie)
            return NULL;
        TreeNode* ans = new TreeNode(postorder[pe-1]);
        int i = is;
        for(; i < ie; i++) {
            if(inorder[i] == postorder[pe-1])
                break;
        }
        ans->left = helper(postorder, ps, ps+(i-is), inorder, is, i);
        ans->right = helper(postorder, ps+(i-is), pe-1, inorder, i+1, ie);
        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
};
