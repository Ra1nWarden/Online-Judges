#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

const int maxn = 1e5;
int v[maxn+5];
int m[maxn+5];
int ans[maxn+5];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            m[v[i]] = i;
        }
        priority_queue<int> pq;
        for(int i = (m[n] & 1) ? 1 : 2; i <= n; i += 2) {
            pq.push(v[i]);
        }
        int fill = n / 2 + 1;
        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();
            ans[m[u]] = fill++;
        }
        fill = 1;
        for(int i = (m[n] & 1) ? 2 : 1; i <= n; i += 2) {
            pq.push(v[i]);
        }
        while(!pq.empty()) {
            int u = pq.top();
            pq.pop();
            ans[m[u]] = fill++;
        }
        for(int i = 1; i <= n; i++) {
            if(i > 1)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}