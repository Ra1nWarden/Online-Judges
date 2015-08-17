class Solution {
private:
    vector<int> dp;
    vector<vector<int> > pdp;
    bool palindrome(int i, int j, const string& s) {
        if(i > j)
            return true;
        if(pdp[i][j] != -1)
            return pdp[i][j];
        if(s[i] != s[j])
            return pdp[i][j] = false;
        else
            return pdp[i][j] = palindrome(i+1, j-1, s);
    }
public:
    int minCut(string s) {
        for(int i = 0; i < s.length(); i++)
            dp.push_back(-1);
        for(int i = 0; i < s.length(); i++)
            pdp.push_back(dp);
        dp.push_back(0);
        for(int i = s.length() - 1; i > -1; i--) {
            dp[i] = s.length() - i;
            for(int j = i; j < s.length(); j++) {
                if(palindrome(i, j, s)) {
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
        return dp[0] - 1;
    }
};
