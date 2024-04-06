#include <cstdio>

using namespace std;

const int maxn = 50;
char v[maxn+5];
int n;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d\n", &n);
        scanf("%s", v);
        int total = 0;
        int a = -1, b = -1;
        for(int i = 0; i < n; i++) {
            if(v[i] == '1') {
                if(a == -1) {
                    a = i;
                } else if(b == -1) {
                    b = i;
                }
                total++;
            }
        }
        bool ok = !(total & 1);
        if(total == 2) {
            ok = (b != a+1);
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}