/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root != NULL)
            q.push(root);
        while(!q.empty()) {
            queue<TreeLinkNode*> qq;
            while(!q.empty()) {
                TreeLinkNode* u = q.front();
                q.pop();
                if(u->left != NULL)
                    qq.push(u->left);
                if(u->right != NULL)
                    qq.push(u->right);
                if(!q.empty()) {
                    u->next = q.front();
                }
            }
            q = qq;
        }
    }
};
