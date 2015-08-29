typedef pair<int, int> Node;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if(grid.empty()) {
            return ans;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    queue<Node> q;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    ans++;
                    while(!q.empty()) {
                        Node u = q.front();
                        q.pop();
                        for(int dir = 0; dir < 4; dir++) {
                            int xx = u.first + dx[dir];
                            int yy = u.second + dy[dir];
                            if(xx < 0 || xx >= m || yy < 0 || yy >= n)
                                continue;
                            if(grid[xx][yy] == '0' || visited[xx][yy])
                                continue;
                            visited[xx][yy] = true;
                            q.push(make_pair(xx, yy));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
