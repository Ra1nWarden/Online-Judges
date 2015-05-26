class Solution {
public:
    bool f(int i, vector<int>& dp, vector<int>& nums) {
        if(dp[i] != -1) {
            return dp[i] == 1;
        }
        bool ok = false;
        for(int ii = i - 1; ii > -1; ii--) {
            if(nums[ii] + ii >= i) {
                ok = f(ii, dp, nums);
            }
            if(ok)
                break;
        }
        dp[i] = ok ? 1 : 0;
        return ok;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = 1;
        return f(nums.size() - 1, dp, nums);
    }
};
