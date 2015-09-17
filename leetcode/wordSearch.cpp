class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool found(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string word) {
        if(board[x][y] == word[0]) {
            if(word.length() == 1)
                return true;
            visited[x][y] = true;
            for(int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size() || visited[xx][yy])
                    continue;
                if(found(board, xx, yy, visited, word.substr(1)))
                    return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(found(board, i, j, visited, word))
                    return true;
            }
        }
        return false;
    }
};
