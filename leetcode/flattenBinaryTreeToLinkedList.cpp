/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef pair<TreeNode*, TreeNode*> Ans;
 
class Solution {
private:
    Ans helper(TreeNode* root) {
        if(root->left == NULL && root->right != NULL) {
            Ans rightAns = helper(root->right);
            root->right = rightAns.first;
            return make_pair(root, rightAns.second);
        } else if(root->left != NULL && root->right != NULL){
            Ans leftAns = helper(root->left);
            Ans rightAns = helper(root->right);
            leftAns.second->right = root;
            root->left = NULL;
            root->right = leftAns.first;
            leftAns.second->right = rightAns.first;
            return make_pair(root, rightAns.second);
        } else if(root->left != NULL && root->right == NULL) {
            Ans leftAns = helper(root->left);
            root->left = NULL;
            root->right = leftAns.first;
            return make_pair(root, leftAns.second);
        } else {
            return make_pair(root, root);
        }
    }
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        Ans ans = helper(root);
        root = ans.first;
    }
};
