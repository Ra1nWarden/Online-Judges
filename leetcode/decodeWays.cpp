class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        if(s.length() == 0 || s[0] == '0')
            return 0;
        dp[0] = 1;
        for(int i = 1; i < s.length(); i++) {
            int dig = s[i] - '0';
            int num = atoi(s.substr(i-1, 2).c_str());
            if (num > 26) {
                if(dig == 0) {
                    return 0;
                } else {
                    dp[i] = dp[i-1];  
                }
            } else if (num > 9) {
                if(dig == 0) {
                    if(i > 1)
                        dp[i] = dp[i-2];
                    else
                        dp[i] = 1;
                } else {
                    if(i > 1)
                        dp[i] = dp[i-2] + dp[i-1];
                    else
                        dp[i] = dp[i-1] + 1;
                }
            } else {
                if(dig == 0)
                    return 0;
                else
                    dp[i] = dp[i-1];
            }
        }
        return dp[s.length() - 1];
    }
};
