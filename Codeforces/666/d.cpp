#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n;

int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        sort(v, v+n);
        if(v[n-1] * 2 > sum) {
            printf("T\n");
        } else if(sum & 1) {
            printf("T\n");
        } else {
            printf("HL\n");
        }
    }
    return 0;
}