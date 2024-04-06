#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e5;
int av[maxn+5];
int pv[maxn+5];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &av[i]);
        int mex = n;
        for(int i = n-1; i >= 0; i--) {
            pv[i] = mex - av[i];
            mex = min(mex, pv[i]);
        }
        for(int i = 0; i < n; i++) {
            if(i)
                printf(" ");
            printf("%d", pv[i]);
        }
        printf("\n");
    }
    return 0;
}