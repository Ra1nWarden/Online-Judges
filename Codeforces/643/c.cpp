#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    long long ans = 0;
    for(int xy = c+1; xy <= b+c; xy++) {
        int y_max = xy - a;
        int y_min = xy - b;
        int ways = min(y_max, c) - max(y_min, b) + 1;
        if(ways <= 0) {
            continue;
        }
        int z_max = min(xy - 1, d);
        int z_way = z_max - c + 1;
        ans += ways * 1LL * z_way;
    }
    printf("%lld\n", ans);
    return 0;
}
