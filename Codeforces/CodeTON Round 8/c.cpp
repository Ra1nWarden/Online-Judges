#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5;
int n, x, y;
int v[maxn+5];

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d", &n, &x, &y);
        for(int i = 0; i < x; i++)
            scanf("%d", &v[i]);
        sort(v, v+x);
        int ans = x - 2;
        vector<int> dv;
        for(int i = 0; i < x; i++) {
            int d;
            if(i)
                d = v[i] - v[i-1];
            else
                d = v[i] + n - v[x-1];
            if(d == 2) {
                ans++;
            } else if(d > 2) {
                dv.push_back(d + 1);
            }
        }
        sort(dv.begin(), dv.end());
        for(int i = lower_bound(dv.begin(), dv.end(), 5) - dv.begin(); i < dv.size() && y; i++) {
            if(!(dv[i] & 1))
                continue;
            int select = (dv[i] - 5) / 2 + 1;
            if(y >= select) {
                ans += (2 * select) + 1;
                y -= select;
                dv[i] = 0;
            } else {
                break;
            }
        }
        for(int i = 0; i < dv.size() && y; i++) {
            if(dv[i] < 4) {
                continue;
            }
            int select = min((dv[i] - 1) / 2, y);
            ans += (2 * select);
            y -= select;
        }
        printf("%d\n", ans);
    }
    return 0;
}