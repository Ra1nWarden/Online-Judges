class Solution {
private:
    bool board[100][100];
    int n;
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, 1, -1};
    bool ok(int i, int j) {
        for(int ii = 0; ii < i; ii++) {
            if(board[ii][j])
                return false;
        }
        for(int dir = 0; dir < 4; dir++) {
            for(int ii = 1; ii > 0; ii++) {
                int xx = i + dx[dir] * ii;
                int yy = j + dy[dir] * ii;
                if(xx < 0 || xx >= n || yy < 0 || yy >= n)
                    break;
                if(board[xx][yy])
                    return false;
            }
        }
        return true;
    }
    void solve(int row, vector<vector<string> >& ans, vector<string>& each) {
        if(row == n) {
            ans.push_back(each);
            return;
        }
        string row_str(n, '.');
        for(int i = 0; i < n; i++) {
            if(ok(row, i)) {
                vector<string> each_new = each;
                string row_str_new = row_str;
                row_str_new[i] = 'Q';
                each_new.push_back(row_str_new);
                board[row][i] = true;
                solve(row+1, ans, each_new);
                board[row][i] = false;
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        memset(board, false, sizeof board);
        vector<string> each;
        vector<vector<string> > ans;
        solve(0, ans, each);
        return ans;
    }
};
