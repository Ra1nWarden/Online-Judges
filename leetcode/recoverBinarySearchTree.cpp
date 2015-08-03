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
    int maxVal(TreeNode* node) {
        int ans = node->val;
        if(node->left != NULL)
            ans = max(ans, maxVal(node->left));
        if(node->right != NULL)
            ans = max(ans, maxVal(node->right));
        return ans;
    }
    int minVal(TreeNode* node) {
        int ans = node->val;
        if(node->left != NULL)
            ans = min(ans, minVal(node->left));
        if(node->right != NULL)
            ans = min(ans, minVal(node->right));
        return ans;
    }
    bool swapNum(int orig, int newval, TreeNode* root) {
        if(root == NULL)
            return false;
        if(root->val == orig) {
            root->val = newval;
            return true;
        }
        if(root->left != NULL && swapNum(orig, newval, root->left))
            return true;
        if(root->right != NULL && swapNum(orig, newval, root->right))
            return true;
        return false;
    }
public:
    void recoverTree(TreeNode* root) {
        int num = root->val;
        if(root->left != NULL && root->right != NULL) {
            int leftMax = maxVal(root->left);
            int rightMin = minVal(root->right);
            if(num > leftMax && num < rightMin) {
                recoverTree(root->left);
                recoverTree(root->right);
            } else if(num < leftMax && num > rightMin) {
                swapNum(leftMax, rightMin, root->left);
                swapNum(rightMin, leftMax, root->right);
            } else if(num > rightMin) {
                root->val = rightMin;
                swapNum(rightMin, num, root->right);
            } else if(num < leftMax) {
                root->val = leftMax;
                swapNum(leftMax, num, root->left);
            }
        } else if(root->left == NULL && root->right == NULL) {
            return;
        } else if(root->left == NULL) {
            int rightMin = minVal(root->right);
            if(num < rightMin)
                recoverTree(root->right);
            else {
                root->val = rightMin;
                swapNum(rightMin, num, root->right);
            }
        } else {
            int leftMax = maxVal(root->left);
            if(num > leftMax)
                recoverTree(root->left);
            else {
                root->val = leftMax;
                swapNum(leftMax, num, root->left);
            }
        }
    }
};
