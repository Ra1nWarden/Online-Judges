#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 5000;
char str[maxn+5];
int n;

bool check(int len) {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        while(!q.empty()) {
            int u = q.front();
            if(u + len > i) {
                break;
            }
            q.pop();
        }
        bool bit = (str[i] == '1');
        bit ^= (q.size() & 1);
        if(!bit) {
            if(i + len <= n)
                q.push(i);
            else
                return false;
        }
    }
    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d\n%s", &n, str);
        int len;
        for(len = n; len > 1; len--) {
            if(check(len)) {
                break;
            }
        }
        printf("%d\n", len);
    }
    return 0;
}