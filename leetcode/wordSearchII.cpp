class Solution {
private:
    unordered_set<string> dict;
    unordered_set<string> prefix;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    void dfs(vector<vector<char> >& board, int i, int j, string candidate, vector<vector<bool> >& visited, vector<string>& ans) {
        if(prefix.count(candidate) == 0)
            return;
        if(dict.count(candidate))
            ans.push_back(candidate);
        for(int dir = 0; dir < 4; dir++) {
            int ii = i + dx[dir];
            int jj = j + dy[dir];
            if(ii < 0 || jj < 0 || ii >= m || jj >= n || visited[ii][jj])
                continue;
            visited[ii][jj] = true;
            dfs(board, ii, jj, candidate + board[ii][jj], visited, ans);
            visited[ii][jj] = false;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            dict.insert(words[i]);
            for(int j = 1; j <= words[i].length(); j++) {
                prefix.insert(words[i].substr(0, j));
            }
        }
        vector<string> ans;
        m = board.size();
        if(m == 0)
            return ans;
        n = board.front().size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string candidate = "";
                candidate += board[i][j];
                visited[i][j] = true;
                dfs(board, i, j, candidate, visited, ans);
                visited[i][j] = false;
            }
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};
