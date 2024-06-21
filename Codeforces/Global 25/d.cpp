#include <cstdio>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if(k > n) {
            printf("NO\n");
        } else if(k == n) {
            printf("YES\n");
            printf("1\n");
            printf("1\n");
        } else if(2*k - 2 >= n) {
            printf("NO\n");
        } else {
            printf("YES\n");
            printf("2\n");
            printf("%lld 1\n", n - k + 1);
        }
    }
    return 0;
}