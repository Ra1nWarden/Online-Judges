#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int mod = 998244353;
int n;
map<int, int> nv;
map<int, int> last;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if(last.count(num)) {
            nv[last[num]] = i;
        }
        last[num] = i;
    }
    long long ans = 1LL;
    int end = 0;
    for(int i = 0; i < n; i++) {
        if(i <= end) {
            if(nv.count(i))
                end = max(end, nv[i]);
        } else {
            ans = (ans << 1) % mod;
            end = nv.count(i) ? nv[i] : -1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}