class Solution {
private:
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                int dead = 0, live = 0;
                for(int dir = 0; dir < 8; dir++) {
                    int ii = i + dx[dir];
                    int jj = j + dy[dir];
                    if(ii < 0 || ii >= board.size() || jj < 0 || jj >= board[i].size()) {
                        continue;
                    }
                    // 2: used to be 1 become 0
                    // 3: used to be 0 become 1
                    if(board[ii][jj] == 0 || board[ii][jj] == 3) {
                        dead++;
                    } else if(board[ii][jj] == 1 || board[ii][jj] == 2) {
                        live++;
                    }
                }
                if(board[i][j] == 0) {
                    if(live == 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if(live < 2) {
                        board[i][j] = 2;
                    } else if(live > 3) {
                        board[i][j] = 2;               
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                } else if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
