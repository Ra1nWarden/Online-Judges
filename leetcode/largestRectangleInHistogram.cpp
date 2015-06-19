class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        height.push_back(0);
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            if(s.empty() || height[s.top()] < height[i]) {
                s.push(i);
            } else {
                int next = s.top();
                s.pop();
                ans = max(ans, height[next] * (s.empty() ? i : i - s.top() - 1));
                i--;
            }
        }
        return ans;
    }
};
