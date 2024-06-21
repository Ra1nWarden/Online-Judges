#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

const int maxn = 1000;
int n, m, p;
char board[maxn+5][maxn+5];
int vis[maxn+5][maxn+5];
int sv[maxn+5];
int ans[10];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

struct Node {
    int x, y, idx, round, step;
    Node(int a, int b, int c, int d, int e) : x(a), y(b), idx(c), round(d), step(e) {} 
    bool operator<(const Node& rhs) const {
        if(round != rhs.round) {
            return round > rhs.round;
        }
        if(idx != rhs.idx) {
            return idx > rhs.idx;
        }
        return step > rhs.step;
    }
};

int main() {
    scanf("%d %d %d\n", &n, &m, &p);
    for(int i = 1; i <= p; i++)
        scanf("%d", &sv[i]);
    scanf("\n");
    for(int i = 0; i < n; i++)
        scanf("%s\n", board[i]);
    memset(vis, -1, sizeof vis);
    priority_queue<Node> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char& c = board[i][j];
            if(c == '#') {
                vis[i][j] = 0;
                continue;
            }
            if(c == '.') {
                continue;
            }
            vis[i][j] = c - '0';
            pq.emplace(i, j, c - '0', 0, 0);
        }
    }
    while(!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        if(u.step == sv[u.idx]) {
            pq.emplace(u.x, u.y, u.idx, u.round + 1, 0);
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int xx = u.x + dx[dir];
            int yy = u.y + dy[dir];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if(vis[xx][yy] != -1)
                continue;
            vis[xx][yy] = u.idx;
            pq.emplace(xx, yy, u.idx, u.round, u.step + 1);
        }
    }

    memset(ans, 0, sizeof ans);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0 || vis[i][j] == -1)
                continue;
            ans[vis[i][j]]++;
        }
    }

    for(int i = 1; i <= p; i++) {
        if(i > 1)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}