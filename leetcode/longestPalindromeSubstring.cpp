class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof dp);
        int maxlength = 0;
        int start = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + i < n; j++) {
                if(i == 0) {
                    dp[j][j+i] = true;
                } else if(i == 1) {
                    dp[j][j+i] = s[j] == s[i+j] ? true : false;  
                } else {
                    dp[j][j+i] = s[j] == s[i+j] ? dp[j+1][j+i-1] : false;   
                }
                if(i + 1 > maxlength && dp[j][j+i]) {
                    maxlength = i + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxlength);
    }
};
