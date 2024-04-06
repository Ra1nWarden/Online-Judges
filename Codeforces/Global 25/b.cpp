#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int v[maxn+5];
int n, k;

int run(int idx) {
    int ans = 0;
    for(int i = idx + 1; i <= n; i++) {
        if(v[i] < v[idx]) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
        }
        int ans = 0;
        int large;
        for(large = 1; large < k; large++) {
            if(v[large] > v[k]) {
                break;
            }
        }
        // stay
        if(large > k)
            ans = max(ans, run(k) + 1);
        // swap with 1
        swap(v[1], v[k]);
        ans = max(ans, run(1));
        swap(v[1], v[k]);
        // swap with first large
        if(large < k) {
            swap(v[large], v[k]);
            ans = max(ans, run(large) + ((large > 1) ? 1 : 0));
        }
        
        printf("%d\n", ans);
    }
    return 0;
}