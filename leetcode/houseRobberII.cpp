class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        if(end < start)
            return 0;
        vector<vector<int> > dp(nums.size(), vector<int>(2, 0));
        for(int i = end; i >= start; i--) {
            if(i == end) {
                dp[i][0] = 0;
                dp[i][1] = nums[i];
            } else {
                dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
                dp[i][1] = dp[i+1][0] + nums[i];
            }
        }
        return max(dp[start][0], dp[start][1]);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        else
            return max(solve(nums, 2, nums.size() - 2) + nums[0], solve(nums, 1, nums.size() - 1));
    }
};
