#include <cstdio>
#include <cstring>
#define MAXN 25

using namespace std;

int n, r;
double prob[MAXN];
double sum[MAXN];
bool selected[MAXN];
double cond;

void dfs(int left, int next) {
  if(left == 0) {
    double p = 1.0;
    for(int i = 0; i < n; i++) {
      if(selected[i])
	p *= prob[i];
      else
	p *= (1 - prob[i]); 
    }
    for(int i = 0; i < n; i++) {
      if(selected[i])
	sum[i] += p;
    }
    cond += p;
    return;
  }
  if(n - next + 1 < left)
    return;
  for(int i = next; i < n; i++) {
    selected[i] = true;
    dfs(left - 1, i + 1);
    selected[i] = false;
  }
}

int main() {
  int kase = 1;
  while(scanf("%d %d", &n, &r) != EOF && (n || r)) {
    cond = 0.0;
    for(int i = 0; i < n; i++) {
      scanf("%lf", &prob[i]);
      sum[i] = 0.0;
    }
    memset(selected, false, sizeof selected);
    dfs(r, 0);
    printf("Case %d:\n", kase++);
    for(int i = 0; i < n; i++) {
      printf("%.6f\n", sum[i] / cond);
    }
  }
  return 0;
}
