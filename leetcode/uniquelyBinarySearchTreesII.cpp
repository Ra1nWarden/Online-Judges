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
    vector<TreeNode*> helper(int base, int count) {
        vector<TreeNode*> ans;
        if(count == 0) {
            ans.push_back(NULL);
            return ans;
        }
        for(int leftCount = 0; leftCount < count; leftCount++) {
            int rightCount = count -1 - leftCount;
            vector<TreeNode*> leftTree = helper(base, leftCount);
            vector<TreeNode*> rightTree = helper(base+leftCount+1, rightCount);
            for(int i = 0; i < leftTree.size(); i++) {
                for(int j = 0; j < rightTree.size(); j++) {
                    TreeNode* root = new TreeNode(base + leftCount);
                    root->left = leftTree[i];
                    root->right = rightTree[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
