class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }
        if(k >= prices.size()) {
            int ans = 0;
            for(int i = 0; i < prices.size() - 1; i++) {
                ans += max(0, prices[i+1] - prices[i]);
            }
            return ans;
        }
        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);
        for(int i = 0; i < prices.size() - 1; i++) {
            int change = prices[i+1] - prices[i];
            for(int j = k; j >= 1; j--){
                local[j] = max(local[j] + change, global[j-1] + max(0, change));
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
};
