class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.empty())
            return ans;
        int prev = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - prev);
            prev = min(prices[i], prev);
        }
        return ans;
    }
};
