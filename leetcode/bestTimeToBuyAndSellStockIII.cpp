class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() < 1) {
            return ans;
        }
        int min_val = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > min_val) {
                if(i != prices.size() - 1 && prices[i+1] > prices[i])
                    continue;
                int sub_ans = prices[i] - min_val;
                int j = i+1;
                if(j < prices.size()) {
                    int sub_res = 0;
                    int sub_min_val = prices[j];
                    for(++j; j < prices.size(); j++) {
                        if(prices[j] > sub_min_val) {
                            if(j != prices.size() - 1 && prices[j+1] > prices[j])
                                continue;
                            sub_res = max(sub_res, prices[j] - sub_min_val);
                        } else {
                            sub_min_val = prices[j];
                        }
                    }
                    sub_ans += sub_res;
                }
                ans = max(ans, sub_ans);
            } else {
                min_val = prices[i];
            }
        }
        return ans;
    }
};
