class Solution {
private:
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int dir = 0;
        int i = 0, j = 0;
        int m = matrix.size(), n = 0;
        if(m > 0)
            n = matrix[0].size();
        while(ans.size() < m * n) {
            ans.push_back(matrix[i][j]);
            switch(dir) {
                case 0:
                    if(j == n - 1 - i) {
                        dir = (dir + 1) % 4;
                    }
                    break;
                case 1:
                    if(i == m - 1 - (n - 1 - j)) {
                        dir = (dir + 1) % 4;
                    }
                    break;
                case 2:
                    if(j == m - 1 - i) {
                        dir = (dir + 1) % 4;
                    }
                    break;
                case 3:
                    if(i == j + 1) {
                        dir = (dir + 1) % 4;
                    }
            }
            i += dx[dir];
            j += dy[dir];
        }
        return ans;
    }
};
