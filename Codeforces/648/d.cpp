#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

const int maxn = 50;
char board[maxn+5][maxn+5];
bool vis[maxn+5][maxn+5];
int n, m;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
typedef pair<int, int> II;

bool block_bad() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] != 'B') {
                continue;
            }
            for(int dir = 0; dir < 4; dir++) {
                int ii = i + dx[dir];
                int jj = j + dy[dir];
                if(ii < 0 || jj < 0 || ii >= n || jj >= m)
                    continue;
                if(board[ii][jj] == 'G') {
                    return false;
                } else if(board[ii][jj] == '.') {
                    board[ii][jj] = '#';
                }
            }
        }
    }
    return true;
}

bool check_good() {
    memset(vis, false, sizeof vis);
    queue<II> q;
    if(board[n-1][m-1] != '#') {
        q.push(make_pair(n-1, m-1));
        vis[n-1][m-1] = true;
    }
    while(!q.empty()) {
        II u = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int ii = u.first + dx[dir];
            int jj = u.second + dy[dir];
            if(ii < 0 || jj < 0 || ii >= n || jj >= m)
                continue;
            if(vis[ii][jj])
                continue;
            if(board[ii][jj] == '#')
                continue;
            vis[ii][jj] = true;
            q.push(make_pair(ii, jj));
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'G' && !vis[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d\n", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%s", board[i]);
        }

        bool ok = block_bad();

        if(!ok) {
            printf("No\n");
            continue;
        }

        ok = check_good();
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}