class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        for(int i = 0; i < triangle.size(); i++) {
            vector<int> dpp;
            vector<int>& row = triangle[i];
            if(i == 0) {
                dpp.push_back(row[0]);
                dp = dpp;
                continue;
            }
            for(int j = 0; j < row.size(); j++) {
                if(j == 0) {
                    dpp.push_back(row[j] + dp[j]);
                } else if(j != row.size() - 1) {
                    dpp.push_back(row[j] + min(dp[j-1], dp[j]));
                } else {
                    dpp.push_back(row[j] + dp[j-1]);
                }
            }
            dp = dpp;
        }
        int ans = dp[0];
        for(int i = 1; i < dp.size(); i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
