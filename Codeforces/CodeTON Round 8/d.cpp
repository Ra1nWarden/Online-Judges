#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1000;
const int maxk = 5000;
int n, k;
int av[maxn+5][maxn+5];
int dp[maxn+5][maxk+5];
int dpl[maxn+5];
typedef pair<int, pair<int, int> > III;

III make_iii(int a, int b, int c) {
    return make_pair(a, make_pair(b, c));
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                scanf("%d", &av[i][j]);
            }
        }

        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            dpl[i] = i < 13 ? min(k, 1 << i) : k;
        }

        for(int i = 1; i <= n; i++) {
            priority_queue<III> pq;
            pq.push(make_iii(dp[i-1][0], i-1, 0));
            for(int j = i; j >= 1; j--) {
                if(j - 2 < 0) {
                    pq.push(make_iii(av[j][i], -1, -1));
                    break;
                }
                pq.push(make_iii(av[j][i] + dp[j-2][0], j-2, 0));
            }
            for(int j = 0; j < dpl[i]; j++) {
                III u = pq.top();
                pq.pop();
                dp[i][j] = u.first;
                int idx = u.second.first;
                int pos = u.second.second;
                if(idx == -1)
                    continue;
                if(idx == i-1 && pos + 1 < dpl[idx])
                    pq.push(make_iii(dp[idx][pos+1], idx, pos+1));
                if(idx < i-1 && pos + 1 < dpl[idx])
                    pq.push(make_iii(av[idx+2][i] + dp[idx][pos+1], idx, pos+1));
            }
        }

        for(int i = 0; i < k; i++) {
            if(i)
                printf(" ");
            printf("%d", dp[n][i]);
        }
        printf("\n");
    }
}