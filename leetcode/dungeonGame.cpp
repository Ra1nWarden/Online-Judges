class Solution {
private:
    void update(int& val, int change) {
        if(val == -1)
            val = change;
        else
            val = min(val, change);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, -1));
        for(int gap = 0; gap < m + n - 1; gap++) {
            int y = gap > n-1 ? 0 : n-1-gap;
            int x = m-1-(gap-(n-1-y));
            while(x >= 0 && y < n) {
                if(dungeon[x][y] >= 0) {
                    if(x+1 < m) {
                        update(dp[x][y], max(dp[x+1][y] - dungeon[x][y], 0));
                    }
                    if(y+1 < n) {
                        update(dp[x][y], max(dp[x][y+1] - dungeon[x][y], 0));
                    }
                    if(dp[x][y] == -1)
                        dp[x][y] = 0;
                } else {
                    int raw = -dungeon[x][y];
                    if(x+1 < m) {
                        update(dp[x][y], raw + dp[x+1][y]);
                    }
                    if(y+1 < n) {
                        update(dp[x][y], raw + dp[x][y+1]);
                    }
                    if(dp[x][y] == -1)
                        dp[x][y] = raw;
                }
                x--;
                y++;
            }
        }
        return dp[0][0]+1;
    }
};
