#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        double ans = 0.0;
        for(int i = 1; i < n; i++) {
            double pos = (double) i / n * (m+n);
            ans += fabs(pos - floor(pos + 0.5)) / (m + n);
        }
        // remember to add newline character before submitting
        printf("%.4f\n", ans * 10000);
    }
    return 0;
}
