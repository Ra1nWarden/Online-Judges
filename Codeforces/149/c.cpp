#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int x_0, y_0, x_1, y_1;
map<int, vector<int>> am;
map<pair<int, int>, int> vis;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int main() {
    scanf("%d%d%d%d", &x_0, &y_0, &x_1, &y_1);
    int n;
    scanf("%d", &n);
    while(n--) {
        int r, x, y;
        scanf("%d %d %d", &r, &x, &y);
        if(am.count(r)) {
            am[r].push_back(x);
            am[r].push_back(y);
        } else {
            am[r] = vector<int>{x, y};
        }
    }

    for(auto& v : am) {
        sort(v.second.begin(), v.second.end());
    }

    queue<pair<int, int>> q;
    q.push(make_pair(x_0, y_0));
    vis[make_pair(x_0, y_0)] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > 1e9 || ny < 1 || ny > 1e9) continue;
            if(vis.count(make_pair(nx, ny))) continue;
            if(!am.count(nx)) continue;
            vector<int>& s = am[nx];
            int idx = lower_bound(s.begin(), s.end(), ny) - s.begin();
            if(s[idx] != ny && !(idx&1)) continue;
            vis[make_pair(nx, ny)] = vis[make_pair(x, y)] + 1;
            if(nx == x_1 && ny == y_1) {
                break;
            }
            q.push(make_pair(nx, ny));
        }
    }
    printf("%d\n", vis.count(make_pair(x_1, y_1)) ? vis[make_pair(x_1, y_1)] : -1);

    return 0;
}