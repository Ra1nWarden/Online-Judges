#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;

bool buildChess(const vector<string>& orig, int side, const bitset<16>& bits, vector<string>* result) {
    for (int i = 0; i < side; i++) {
        string eachLine = orig[i];    
        for (int j = 0; j < side; j++) {
           if (bits[i * side + j] && eachLine[j] == 'X') {
                return false;    
           } else if (eachLine[j] == '.' && bits[i * side + j]) { 
                eachLine[j] = 'O';
           }
        }
        result->push_back(eachLine);
    } 
    return true;
}

int checkValid(vector<string> board, int side) {
    int result = 0;
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (board[i][j] == 'O') {
                result++;
                for (int k = i+1; k < side; k++) {
                    if (board[k][j] == 'O') {
                        bool ok = false;
                        for (int l = i + 1; l < k; l++) {
                            if (board[l][j] == 'X') {
                                ok = true;
                                break;
                            }    
                        }
                        if (!ok)
                            return 0;
                    }    
                }    
            for (int k = j+1; k < side; k++) {
                if (board[i][k] == 'O') {
                    bool ok = false;
                        for (int l = j + 1; l < k; l++) {
                            if (board[i][l] == 'X') {
                                ok = true;
                                break;
                            } 
                        }
                        if (!ok)
                            return 0;
                    }    
                }
            }
        }
    }
    return result;
}

int main() {
    int side;
    while(cin >> side&& side) {
        vector<string> chess;
        cin >> ws;
        for (int i = 0; i < side; i++) {
            string line;
            getline(cin, line);
            chess.push_back(line);
        }    
        int max = 1 << (side * side);
        int result = 0;
        for (int i = 1; i < max; i++) {
            bitset<16> current(i);
            vector<string> currentBoard;
            if(buildChess(chess, side, current, &currentBoard)) {
                int valid = checkValid(currentBoard, side);
                if (valid > result) {
                    result = valid;    
                }
            }
        }
        cout << result << endl;
    }
    return 0;    
}
