#include <cstdio>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if(n == k) {
            for(int i = 0; i < n; i++) {
                if(i)
                    printf(" ");
                printf("1");
            }
            printf("\n");
        } else if(k == 1) {
            for(int i = 0; i < n - 1; i++) {
                if(i)
                    printf(" ");
                printf("1");
            }
            printf(" 2\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}