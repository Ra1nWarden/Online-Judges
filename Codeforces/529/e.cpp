#include <cstdio>

using namespace std;

const int maxn = 1e6;
char str[maxn+5];
int cnt[maxn+5];
int n;

int main() {
    scanf("%d\n", &n);
    scanf("%s", str);
    int cur = 0;
    
    for(int i = 0; i < n; i++) {
        if(str[i] == '(') {
            cur++;
        } else {
            cur--;
        }
        cnt[i] = cur;
    }
    
    if(cnt[n-1] == -2) {
        int start = -1;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(cnt[i] < -2) {
                ok = false;
                break;
            }
            if(start == -1 && cnt[i] < 0) {
                start = i;
            }
        }
        if(!ok) {
            printf("0\n");
            return 0;
        }
        int ans = 0;
        for(int i = 0; i <= start; i++) {
            if(str[i] == ')') {
                ans++;
            }
        }
        printf("%d\n", ans);
    } else if(cnt[n-1] == 2) {
        int start = -1;
        bool ok = true;
        for(int i = n-1; i >= 0; i--) {
            if(cnt[i] < 0) {
                ok = false;
                break;
            }
            if(start == -1 && cnt[i] < 2) {
                start = i;
            }   
        }
        if(!ok) {
            printf("0\n");
            return 0;
        }
        int ans = 0;
        for(int i = n - 1; i > start; i--) {
            if(str[i] == '(') {
                ans++;
            }
        }
        printf("%d\n", ans);
    } else {
        printf("0\n");
    }

    return 0;
}