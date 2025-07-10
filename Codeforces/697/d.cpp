#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, m;
const int maxn = 200000;
int v1[maxn+5], v2[maxn+5];
int nv[maxn+5];
int v1i, v2i;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &m);
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &nv[i]);
            sum += nv[i];
        }
        v1i = v2i = 0;
        for(int i = 0; i < n; i++) {
            int imp;
            scanf("%d", &imp);
            if(imp == 1) {
                v1[v1i++] = nv[i];
            } else {
                v2[v2i++] = nv[i];
            }
        }
        if(sum < m) {
            printf("-1\n");
            continue;
        }
        sort(v1, v1 + v1i, greater<int>());
        sort(v2, v2 + v2i, greater<int>());
        sum = 0;
        int ans = v2i * 2 + v1i;
        int cur_ans = 0;
        int p1, p2;
        for(p2 = 0; p2 < v2i && sum < m; p2++) {
            sum += v2[p2];
            cur_ans += 2;
        }
        if(sum >= m) {
            ans = min(ans, cur_ans);
        }
        for(p1 = 0; p1 < v1i; p1++) {
            sum += v1[p1];
            cur_ans += 1;
            while(p2 > 0 && sum - v2[p2-1] >= m) {
                sum -= v2[p2-1];
                p2--;
                cur_ans -= 2;
            }
            if(sum >= m) {
                ans = min(ans, cur_ans);
            }
        }
        printf("%d\n", ans);
    }
}