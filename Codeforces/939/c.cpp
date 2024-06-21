#include <cstdio>

using namespace std;

int total (int n) {
    int ans = 0;
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        ans += i * cnt;
        cnt += 2;
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", total(n), 2 * n);
        for(int i = n; i >= 1; i--) {
            printf("1 %d", i);
            for(int j = 1; j <= n; j++)
                printf(" %d", j);
            printf("\n");
            printf("2 %d", i);
            for(int j = 1; j <= n; j++)
                printf(" %d", j);
            printf("\n");
        }
    }
    return 0;
}