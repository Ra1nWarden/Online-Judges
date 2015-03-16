class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int res = 0;
        while(start != end) {
            int next = min(height[start], height[end]) * (end - start);
            res = max(res, next);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return res;
    }
};
