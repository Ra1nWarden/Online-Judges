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
    vector<string> ans;
    void generate(TreeNode* cur, vector<int>& v) {
        v.push_back(cur->val);
        if(cur->left == NULL && cur->right == NULL) {
            stringstream ss;
            for(int i = 0; i < v.size(); i++) {
                if(i != 0) {
                    ss << "->";
                }
                ss << v[i];
            }
            ans.push_back(ss.str());
        }
        if(cur->left != NULL) {
            generate(cur->left, v);
        }
        if(cur->right != NULL) {
            generate(cur->right, v);
        }
        v.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> v;
        if(root)
            generate(root, v);
        return ans;
    }
};
