/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> m;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        if(m.count(node->label))
            return m[node->label];
        UndirectedGraphNode* ans = new UndirectedGraphNode(node->label);
        m[ans->label] = ans;
        for(int i = 0; i < node->neighbors.size(); i++) {
          ans->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return ans;
    }
};
