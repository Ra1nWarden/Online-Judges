typedef pair<int, int> II;
class Solution {
private:
    int m, n;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    unordered_set<int> fail;
    void flood_fill(int x, int y, int num, vector<vector<int> >& visited, const vector<vector<char> >& board) {
        queue<II> q;
        q.push(make_pair(x, y));
        visited[x][y] = num;
        while(!q.empty()) {
            II u = q.front();
            q.pop();
            if(u.first == 0 || u.second == 0 || u.first == m - 1 || u.second == n - 1)
                fail.insert(num);
            for(int i = 0; i < 4; i++) {
                int xx = u.first + dx[i];
                int yy = u.second + dy[i];
                if(xx >= m || yy >= n || xx < 0 || yy < 0)
                    continue;
                if(visited[xx][yy] == 0 && board[xx][yy] == 'O') {
                    visited[xx][yy] = num;
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0)
            return;
        n = board[0].size();
        vector<vector<int> > visited(m, vector<int>(n, 0));
        int num = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X')
                    continue;
                if(visited[i][j] == 0) {
                    flood_fill(i, j, num++, visited, board);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && fail.count(visited[i][j]) == 0)
                    board[i][j] = 'X';
            }
        }
        
    }
};
