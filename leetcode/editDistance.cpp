class Solution {
public:
    int f(int i, int j, string word1, string word2, vector<vector<int> >& dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == word1.length() && j == word2.length()) {
            return dp[i][j] = 0;
        } else if(i == word1.length()) {
            return dp[i][j] = word2.length() - j;
        } else if(j == word2.length()) {
            return dp[i][j] = word1.length() - i;
        } else {
            int ans = min(f(i, j+1, word1, word2, dp) + 1, f(i+1, j, word1, word2, dp) + 1);
            if(word1[i] != word2[j]) {
                ans = min(ans, f(i+1, j+1, word1, word2, dp) + 1);
            } else {
                ans = min(ans, f(i+1, j+1, word1, word2, dp));
            }
            return dp[i][j] = ans;
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return f(0, 0, word1, word2, dp);
    }
};
