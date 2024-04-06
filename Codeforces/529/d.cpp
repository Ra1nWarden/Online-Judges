#include <cstdio>

using namespace std;

const int maxn = 2e5;
int n;
int mat[maxn+5][2];
int ans[maxn+5];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &mat[i][0], &mat[i][1]);
    }
    int cur = 0;
    ans[cur++] = 1;

    if(mat[mat[1][0]][0] == mat[1][1] || mat[mat[1][0]][1] == mat[1][1]) {
        ans[cur] = mat[1][0];
        ans[cur+1] = mat[1][1];
    } else {
        ans[cur] = mat[1][1];
        ans[cur+1] = mat[1][0];
    }

    while(cur + 2 < n) {
        if(mat[ans[cur]][0] == ans[cur+1]) {
            ans[cur+2] = mat[ans[cur]][1];
        } else {
            ans[cur+2] = mat[ans[cur]][0];
        }
        cur++;
    }

    for(int i = 0; i < n; i++) {
        if(i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}