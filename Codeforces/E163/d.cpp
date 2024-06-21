#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 5000;
char str[maxl+5];
int n;

int main() {
    int tc;
    scanf("%d\n", &tc);
    while(tc--) {
        scanf("%s", str);
        n = strlen(str);
        int ans = 0;
        for(int len = 2; len <= n; len += 2) {
            int cur = 0;
            for(int i = 0; i + (len / 2) < n; i++) {
                if(str[i] == '?' || str[i + (len / 2)] == '?' || str[i] == str[i + (len / 2)]) {
                    cur++;
                } else {
                    cur = 0;
                }
                if(cur == len / 2) {
                    ans = len;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}