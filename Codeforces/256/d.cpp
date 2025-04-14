#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    long long left = 1, right = k;
    while(left != right) {
        long long mid = (left + right) >> 1;
        long long cur = 0;
        for(long long i = 1LL; i <= n; i++) {
            cur += min(m, mid / i);
        }
        if(cur >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%lld\n", left);
    return 0;
}