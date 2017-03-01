#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100;

struct Circle {
  double x, y, r;
};

Circle circles[maxn+5];
int n;
vector<double> p[maxn+5];

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++)
      scanf("%lf %lf %lf", &circles[i].x, &circles[i].y, &circles[i].r);
    for(int i = 0; i < n; i++) {
      
    }
  }
  return 0;
}
