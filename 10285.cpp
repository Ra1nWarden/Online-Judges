#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int board[101][101];
int maxSteps[101][101];

void init() {
   memset(board, -1, sizeof board);
   memset(maxSteps, -1, sizeof maxSteps);
}

int findMax(int r, int c, int x, int y) {
   if (maxSteps[x][y] != -1)
        return maxSteps[x][y];
   else {
        int result = -1;
        bool found = false;
        for (int i = x -1; i <= x + 1; i++) {
            if (i < 1 || i > r)
                    continue;
            for (int j = y -1; j <= y+1; j++) {
                if (j < 1 || j > c)
                    continue;
                if (i == x && j == y)
                    continue;
                if (board[i][j] < board[x][y] && (i == x || j == y)) {
                    found = true;
                    int candidate = findMax(r, c, i, j);
                    if (candidate > result)
                        result = candidate;
                }
            }
        }
        if (found)
            maxSteps[x][y] = result+1;
        else
            maxSteps[x][y] = 1;
        return maxSteps[x][y];
   }
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
       string line;
       cin >> ws;
       getline(cin, line); 
       istringstream iss(line.c_str());
       string name;
       int r, c;
       iss >> name >> r >> c;
       init();
       for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
               int number;
               cin >> number;
               board[i][j] = number;
            }
       }
       int result = -1;
       for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int currentNumber = findMax(r, c, i, j);
                if (currentNumber > result)
                        result = currentNumber;
            }
       }
       cout << name << ": " << result << endl;
    }
    return 0;
}
