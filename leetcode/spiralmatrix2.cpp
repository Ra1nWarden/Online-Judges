class Solution {
private:
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        if(n == 0)
            return ans;
        int i = 0, j = 0;
        int dir = 0;
        int fill = 0;
        while(fill <= n * n) {
            ans[i][j] = ++fill;
            if(fill == n * n)
                break;
            switch(dir) {
                case 0:
                    if(j == n - 1 - i)
                        dir = 1;
                    break;
                case 1:
                    if(i == j)
                        dir = 2;
                    break;
                case 2:
                    if(j == n - 1 - i)
                        dir = 3;
                    break;
                case 3:
                    if(i == j+1)
                        dir = 0;
            }
            i += dx[dir];
            j += dy[dir];
        }
        return ans;
    }
};
