#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1e9+7;
const int maxn = 1e5;
char str[maxn+5];

int main() {
    scanf("%s", str);
    int ans = 0, prev_ans = 0;
    for(int i = 0; i >= 0; i++) {
        if(str[i] == '\0') {
            break;
        }
        if(str[i] == 'a') {
            ans = (ans + 1 + prev_ans) % mod;
        } else if(str[i] == 'b') {
            prev_ans = ans;
        } else {
            continue;
        }
    }
    printf("%d\n", ans);
    return 0;
}