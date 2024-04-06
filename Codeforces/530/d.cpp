#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e5;
int fa[maxn+5];
int av[maxn+5];
int sv[maxn+5];
vector<int> children[maxn+5];
int n;
typedef pair<int, int> II;

int main() {
    scanf("%d", &n);
    fa[1] = 1;
    for(int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]);
        children[fa[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sv[i]);
    }
    memset(av, -1, sizeof av);

    av[1] = sv[1];
    queue<int> q;
    q.push(1);
    bool ok = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < children[u].size(); i++) {
            q.push(children[u][i]);
        }

        if(av[u] != -1) {
            continue;
        }

        if(sv[u] != -1) {
            av[u] = sv[u] - sv[fa[u]];
            if(av[u] < 0) {
                ok = false;
                break;
            }
            continue;
        }

        if(children[u].empty()) {
            av[u] = 0;
            continue;
        }

        int min_val = sv[children[u][0]];
        for(int i = 1; i < children[u].size(); i++) {
            min_val = min(min_val, sv[children[u][i]]);
        }
        av[u] = min_val - sv[fa[u]];
        if(av[u] < 0) {
            ok = false;
            break;
        }
        sv[u] = sv[fa[u]] + av[u];
    }

    if(!ok) {
        printf("-1\n");
    } else {
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += av[i];
            //printf("av[%d]=%d\n", i, av[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}