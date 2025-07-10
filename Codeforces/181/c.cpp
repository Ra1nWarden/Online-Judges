#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;
int a, b, n;

int MultModular(int x, int y) {
    x %= mod;
    y %= mod;
    int ret = 0;
    int tmp = x;
    while (y) {
        if (y & 1) {
            ret += tmp;
            if (ret > mod) {
                ret -= mod;
            }
        }
        tmp <<= 1;
        if (tmp > mod) {
            tmp -= mod;
        }
        y >>= 1;
    }
    return ret;
}

int PowerModular(int x, int y) {
    int ret = 1;
    int temp = x % mod;
    while (y) {
        if (y & 1) {
            ret = MultModular(ret, temp);
        }
        temp = MultModular(temp, temp);
        y >>= 1;
    }
    return ret;
}

int choose(int x, int y) {
    if ((y << 1) > x) {
        y = x - y;
    }
    int num = 1;
    int denom = 1;
    for (int i = 1; i <= y; i++) {
        denom = (denom * 1LL * i) % mod;
        num = (num * 1LL * (x - i + 1)) % mod;
    }
    return (num * 1LL * PowerModular(denom, mod - 2)) % mod;
}

int count(int num) {
    int numerator = num - a * n;
    int denominator = b - a;
    if (numerator < 0 || numerator % denominator != 0) {
        return 0;
    }
    int y = numerator / denominator;
    int x = n - y;
    if (x < 0) {
        return 0;
    }
    return choose(n, x);
}

int main() {
    scanf("%d %d %d", &a, &b, &n);
    int lower = a * n, upper = b * n;
    int len;
    int total = 1;
    for (len = 1; len <= 8; len++) {
        total = total * 10;
        if (total > lower) {
            break;
        }
    }
    int bitmask = 0;
    int ans = 0;
    while (true) {
        int num = 0;
        int base = 1;
        for (int i = 0; i < len || (1 << i) <= bitmask; i++) {
            int dig = a;
            if ((1 << i) & bitmask) {
                dig = b;
            }
            num += dig * base;
            base *= 10;
        }
        if (num > upper) {
            break;
        }
        ans += count(num);
        ans %= mod;
        bitmask++;
    }
    printf("%d\n", ans);
    return 0;
}