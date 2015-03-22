class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9];
        bool col[9][9];
        bool square[9][9];
        memset(row, false, sizeof row);
        memset(col, false, sizeof col);
        memset(square, false, sizeof square);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c == '.')
                    continue;
                int cn = c - '1';
                int sn = j / 3 * 3 + i / 3;
                if(square[sn][cn] || row[i][cn] || col[j][cn])
                    return false;
                row[i][cn] = col[j][cn] = square[sn][cn] = true;
            }
        }
        return true;
    }
};
