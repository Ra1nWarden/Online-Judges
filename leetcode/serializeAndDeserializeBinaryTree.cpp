#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<TreeNode*, int> QNode;
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<TreeNode*> nodes;
        queue<TreeNode*> q;
        if(root != NULL) {
            q.push(root);
            nodes.push_back(root);
        }
        while(!q.empty()) {
            TreeNode* u = q.front();
	    q.pop();
            nodes.push_back(u->left);
            if(u->left != NULL) {
                q.push(u->left);
            }
            nodes.push_back(u->right);
            if(u->right != NULL) {
                q.push(u->right);
            }
        }
        stringstream ss;
        ss << "[";
        for(int i = 0; i < nodes.size(); i++) {
            if(i) {
                ss << ",";
            }
            if(nodes[i]) {
                ss << nodes[i]->val;
            } else {
                ss << "null";
            }
        }
        ss << "]";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data.substr(1, data.length() - 2));
        string token;
        vector<TreeNode*> nodes;
        while(getline(ss, token, ',')) {
            if(token == "null") {
                nodes.push_back(NULL);
            } else {
                nodes.push_back(new TreeNode(atoi(token.c_str())));
            }
        }
        if(nodes.empty()) {
            return NULL;
        }
        int parent = 0;
        int cur = 1;
        bool left = true;
        while(cur < nodes.size()) {
            if(nodes[cur] != NULL) {
                if(left) {
                    nodes[parent]->left = nodes[cur];
                } else {
                    nodes[parent]->right = nodes[cur];
                }
            }
            left = !left;
            cur++;
            if(left) {
                for(parent++; parent < nodes.size(); parent++) {
                    if(nodes[parent] != NULL) {
                        break;
                    }
                }
            }
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  Codec codec;
  cout << codec.serialize(root) << endl;
  return 0;
}
