#include <cstdio>

using namespace std;

const int maxn = 200000;
int n;
int v[2][maxn+5];
int vvi;
long long t;

int main() {
  scanf("%d %lld\n", &n, &t);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[0][i]);
  }
  int cur = 0;
  long long ans = 0;
  while(true) {
    long long tt = t;
    vvi = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      if(tt >= v[cur][i]) {
	tt -= v[cur][i];
	v[cur^1][vvi++] = v[cur][i];
	sum += v[cur][i];
      }
    }
    n = vvi;
    if(!n)
      break;
    ans += (t / sum) * n;
    t %= sum;
    cur = cur^1;
  }
  printf("%lld\n", ans);
  return 0;
}
