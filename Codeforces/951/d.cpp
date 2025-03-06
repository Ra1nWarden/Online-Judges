#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5;
const int prime = 3;
char bits[maxn+5];
int n, k;
int hashes[maxn+5];
int rev_hashes[maxn+5];

void init_hashes() {
    int cur = 0;
    int rev_cur = 0;
    int p = prime;
    hashes[0] = rev_hashes[0] = 0;
    for(int i = 0; i < n; i++) {
        hashes[i+1] = cur = (cur + ((bits[i] - '0' + 1) * 1LL * p) % mod ) % mod;
        rev_hashes[i+1] = rev_cur = (rev_cur + ((bits[n - 1 - i] - '0' + 1) * 1LL * p) % mod ) % mod;
        p = (p * 1LL * prime) % mod;
    }
}

int pow(int base) {
    if(base == 0)
        return 1;
    if(base == 1)
        return prime;
    int ans = pow(base >> 1);
    ans = (ans * 1LL * ans) % mod;
    if(base & 1)
        ans = (ans * 1LL * prime) % mod;
    return ans;
}

bool cmp(int h1, int b1, int h2, int b2) {
    h1 = (h1 + mod) % mod;
    h2 = (h2 + mod) % mod;
    if(b1 < b2)
        h1 = (h1 * 1LL * pow(b2 - b1)) % mod;
    else
        h2 = (h2 * 1LL * pow(b1 - b2)) % mod;
    return h1 == h2;
}

int check(char* str) {
    int str_hashes[n+5];
    int cur = 0;
    int p = prime;
    str_hashes[0] = 0;
    for(int i = 0; i < n; i++) {
        str_hashes[i+1] = cur = (cur + ((str[i] - '0' + 1) * 1LL * p) % mod ) % mod;
        p = (p * 1LL * prime) % mod;
    }
    for(int i = 0; i < n; i++) {
        if(cmp(str_hashes[1+i], 1, hashes[n] - hashes[n-1-i], n-i) && cmp(str_hashes[n] - str_hashes[i+1], i+1, rev_hashes[n] - rev_hashes[i+1], i+1)) {
            return i+1;
        }
    }
    return -1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &k);
        scanf("%s", bits);
        init_hashes();
        char str1[n+5], str2[n+5];
        for(int i = 0; i < n; i++) {
            if((i / k) & 1) {
                str1[i] = '0';
                str2[i] = '1';
            } else {
                str1[i] = '1';
                str2[i] = '0';
            }
        }
        str1[n] = str2[n] = '\0';
        
        int ans1 = check(str1);
        int ans2 = check(str2);
        
        if(ans1 == -1 && ans2 == -1) {
            printf("-1\n");
        } else if(ans1 != -1) {
            printf("%d\n", n-ans1 == 0 ? n : n-ans1);
        } else {
            printf("%d\n", n-ans2 == 0 ? n : n-ans2);
        }

    }
    return 0;
}