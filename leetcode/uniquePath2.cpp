class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > v(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j])
                    continue;
                if(i == 0 && j == 0)
                    v[i][j] = 1;
                else {
                    if(i > 0 && obstacleGrid[i-1][j] == 0)
                        v[i][j] += v[i-1][j];
                    if(j > 0 && obstacleGrid[i][j-1] == 0)
                        v[i][j] += v[i][j-1];
                }
            }
        }
        return v[m-1][n-1];
    }
};
