class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> suffix(prices.size(), 0);
        vector<int> dp(prices.size(), 0);
        int running_suffix = 0;
        for(int i = prices.size() - 2; i >= 0; i--) {
            int ans = 0;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= prices[i])
                    continue;
                int curr = prices[j] - prices[i];
                if(j + 2 < prices.size()) {
                    curr += suffix[j+2];
                }
                ans = max(ans, curr);
            }
            running_suffix = max(running_suffix, ans);
            suffix[i] = running_suffix;
            dp[i] = ans;
        }
        int ret = 0;
        for(int i = 0; i < dp.size(); i++) {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
