struct Node {
    int idx;
    int pos;
    bool start;
    bool operator<(const Node& rhs) const {
        return pos < rhs.pos;
    }
    Node(int pos, int idx, bool start) : pos(pos), idx(idx), start(start) {}
};

struct HeapNode {
  int height;
  int idx;
  bool operator<(const HeapNode& rhs) const {
      return height < rhs.height;
  }
  HeapNode(int a, int b) : height(a), idx(b) {}
};

class Solution {
private:
    vector<Node> nodes;
    set<int> in_queue;
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        for(int i = 0; i < buildings.size(); i++) {
            nodes.push_back(Node(buildings[i][0], i, true));
            nodes.push_back(Node(buildings[i][1], i, false));
        }
        sort(nodes.begin(), nodes.end());
        priority_queue<HeapNode> pq;
        for(int i = 0; i < nodes.size();) {
            do {
                if(nodes[i].start) {
                    pq.push(HeapNode(buildings[nodes[i].idx][2], nodes[i].idx));
                    in_queue.insert(nodes[i].idx);
                } else {
                    in_queue.erase(nodes[i].idx);
                }
                i++;
            } while(i < nodes.size() && nodes[i].pos == nodes[i-1].pos);
            int pos = nodes[i-1].pos;
            int height = 0;
            while(!pq.empty()) {
                HeapNode u = pq.top();
                if(in_queue.count(u.idx)) {
                    height = u.height;
                    break;
                } else {
                    pq.pop();
                }
            }
            if(ans.empty() || ans.back().second != height) {
                ans.push_back(make_pair(pos, height));
            }
        }
        return ans;
    }
};
