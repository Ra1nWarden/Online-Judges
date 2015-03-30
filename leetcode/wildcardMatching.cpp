class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int sl = strlen(s);
        int pl = strlen(p);
        bool dp[2][2];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int i = 0; i <= sl; i++) {
            bool ok = false;
            for(int j = 1; j <= pl; j++) {
                if(p[j-1] == '*') {
                    dp[i&1][j&1] = dp[i&1][j&1] || (i == 0 ? true : (dp[(i-1)&1][j&1] || dp[(i-1)&1][(j-1)&1]));
                }
                else if(p[j-1] == '?') {
                    dp[i&1][j&1] = dp[i&1][j&1] || (i == 0 ? false : dp[(i-1)&1][(j-1)&1]);
                }
                else {
                    dp[i&1][j&1] = dp[i&1][j&1] || (i == 0 ? false : (s[i-1] == p[j-1] && dp[(i-1)&1][(j-1)&1]));
                }
                ok = ok || dp[i&1][j&1];
            }
            if(!ok)
                return false;
        }
        return dp[sl&1][pl&1];
    }
};
