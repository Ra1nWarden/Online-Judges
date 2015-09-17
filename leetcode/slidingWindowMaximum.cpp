typedef pair<int, int> DequeNode;

class Solution {
private:
    deque<DequeNode> q;
    void insert_node(const DequeNode& node) {
        while(!q.empty()) {
            DequeNode u = q.front();
            if(u.second < node.second)
                q.pop_front();
            else
                break;
        }
        q.push_front(node);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            insert_node(make_pair(i, nums[i]));
            if(i >= k - 1) {
                if(i - q.back().first >= k)
                    q.pop_back();
                ans.push_back(q.back().second);
            }
        }
        return ans;
    }
};
