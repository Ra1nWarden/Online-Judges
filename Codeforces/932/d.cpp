#include <cstdio>

using namespace std;

const int maxn = 3e5;
int v[maxn+5];

long long choose_two(int m) {
    if(m < 2) return 0;
    return m * 1LL * (m - 1) / 2;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n, c;
        scanf("%d %d", &n, &c);
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            if(v[i]&1) {
                odd++;
            } else {
                even++;
            }
        }
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += v[i] / 2 + 1;
            total += c - v[i] + 1;
        }
        total -= n;
        total -= choose_two(odd);
        total -= choose_two(even);
        long long sum = (1 + c + 1) * 1LL * (c + 1) / 2;
        printf("%lld\n", sum - total);
    }
    return 0;
}