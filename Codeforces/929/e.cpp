#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int v[maxn+5];
int pre[maxn+5];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &v[i]);
        int sum = 0;
        pre[0] = 0;
        for(int i = 1; i <= n; i++) {
            sum += v[i];
            pre[i] = sum;
        }
        int q;
        scanf("%d", &q);
        bool start = true;
        while(q--) {
            if(!start) {
                printf(" ");
            }
            int l, u;
            scanf("%d %d", &l, &u);
            int r = lower_bound(pre + l, pre + n + 1, pre[l-1] + u) - pre;
            
            if(r > n) {
                r = n;
            }
            int diff = u * 2 - (pre[r-1] - pre[l-1] + pre[r-1] - pre[l-1] + v[r] - 1);
            if(diff <= 0 && r > l)
                r--;
            
            start = false;
            printf("%d", r);
        }
        printf("\n");
    }
    return 0;
}