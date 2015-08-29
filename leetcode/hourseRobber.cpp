class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<vector<int> > dp(nums.size(), vector<int>(2, 0));
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                dp[i][0] = 0;
                dp[i][1] = nums[0];
            } else if(i == 1) {
                dp[i][0] = nums[0];
                dp[i][1] = nums[1];
            } else {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + nums[i];
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
