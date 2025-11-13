#include <cstdio>

using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n;
        scanf("%d", &n);
        if(n == 1) {
            printf("a\n");
            continue;
        }
        if(n == 2) {
            printf("ab\n");
            continue;
        }
        if(n == 3) {
            printf("abc\n");
            continue;
        }
        for(int i = 0; i < (n - 2) / 2 + 1; i++) {
            printf("a");
        }
        printf("b");
        for(int i = 0; i < (n - 2) / 2; i++) {
            printf("a");
        }
        if(n & 1) {
            printf("c");
        }
        printf("\n");
    }
    return 0;
}