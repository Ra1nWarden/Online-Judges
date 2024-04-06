#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 3e5;
int v[maxn+5];
int bv[maxn+5];
int n, m, k;

struct II {
    int idx;
    int val;
    bool operator<(const II& rhs) const {
        if(val != rhs.val) {
            return val > rhs.val;
        }
        return idx < rhs.idx;
    }
};

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d", &n, &m, &k);
        priority_queue<II> pq;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            pq.push(II {i, v[i]});
        }
        memset(bv, 0, sizeof bv);
        while(!pq.empty() && k) {
            II u = pq.top();
            pq.pop();
            int take = min(k, m);
            bv[u.idx] = take;
            k -= take;
        }
        long long ans = 0;
        int bought = 0;
        for(int i = 0; i < n; i++) {
            if(bv[i] != 0) {
                ans += bv[i] * 1LL * (v[i] + bought);
                bought += bv[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}