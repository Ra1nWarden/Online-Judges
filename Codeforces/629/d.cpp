#include <cstdio>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int n;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        bool equal = true;
        bool link = false;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            if(equal && i && v[i] != v[i-1]) {
                equal = false;
            }
            if(!link && i && v[i] == v[i-1]) {
                link = true;
            }
        }
        bool link_last = v[0] == v[n-1];
        if(equal) {
            printf("1\n");
            for(int i = 0; i < n; i++) {
                if(i) {
                    printf(" ");
                }
                printf("1");
            }
            printf("\n");
            continue;
        }
        if(n & 1) {
            if(link_last) {
                printf("2\n");
                for(int i = 0; i < n; i++) {
                    if(i)
                        printf(" ");
                    if(i & 1) {
                        printf("1");
                    } else {
                        printf("2");
                    }
                }
                printf("\n");
            } else if(link) {
                printf("2\n");
                bool one = true;
                bool swapped = false;
                for(int i = 0; i < n; i++) {
                    if(i) {
                        printf(" ");
                        if(!swapped && v[i] == v[i-1]) {
                            one = !one;
                            swapped = true;
                        }
                    }
                    printf("%d", one ? 1 : 2);
                    one = !one;
                }
                printf("\n");
            } else {
                printf("3\n");
                for(int i = 0; i < n - 1; i++) {
                    if(i & 1) {
                        printf("1 ");
                    } else {
                        printf("2 ");
                    }
                }
                printf("3\n");
            }
        } else {
            printf("2\n");
            for(int i = 0; i < n; i++) {
                if(i)
                    printf(" ");
                if(i & 1) {
                    printf("1");
                } else {
                    printf("2");
                }
            }
            printf("\n");
        }
    }
    return 0;
}