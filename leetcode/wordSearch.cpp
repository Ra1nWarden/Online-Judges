#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<char> > board;
    string word;
    int m, n;
    int dx[4] = {-1 , 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
public:
    bool backtrack(int i, int j, int x, vector<vector<bool> >& check) {
        if(i >= m || j >= n)
            return false;
        if(board[i][j] == word[x]) {
            if(x == word.length() - 1)
                return true;
            for(int dir = 0; dir < 4; dir++) {
                int ii = i + dx[dir];
                int jj = j + dy[dir];
                if(ii > -1 && ii < m && jj > -1 && jj < n && !check[ii][jj]) {
                    check[ii][jj] = true;
                    if(backtrack(ii, jj, x+1, check))
                        return true;
                    check[ii][jj] = false;
                }                
            }
        } else {
            return false;
        }
    }
    bool exist(vector<vector<char> >& board, string word) {
        this->board = board;
        this->word = word;
        m = board.size();
        n = board[0].size();
        if(word.length() == 0)
            return true;
        vector<vector<bool> > check(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                check[i][j] = true;
                if(backtrack(i, j, 0, check)) {
                    return true;
                }
                check[i][j] = false;
            }
        }
        return false;
    }
};

int main() {
  Solution sol;
  vector<vector<char> > input;
  vector<char> a{'a', 'b'};
  vector<char> b{'c', 'd'};
  input.push_back(a);
  input.push_back(b);
  cout << sol.exist(input, "abcd") << endl;
}
