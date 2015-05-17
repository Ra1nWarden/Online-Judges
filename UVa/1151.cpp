#include <algorithm>
#include <vector>
#include <cstdio>
#define MAXN 1005
#define MAXQ 10
#define MAXM 1000005

using namespace std;

int cost[MAXQ];
vector<int> pack[MAXQ];
int n, q;
int x[MAXN];
int y[MAXN];
int p[MAXN];
int u[MAXM], v[MAXM], w[MAXM];
int idx[MAXM];
int mi;
int useful[MAXM];
int ui;

int find(int xx) {
  return p[xx] == xx ? xx : p[xx] = find(p[xx]);
}

int cmp(int i, int j) {
  return w[i] < w[j];
}

void init_union_find() {
  for(int i = 1; i <= n; i++)
    p[i] = i;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &q);
    int cnt;
    for(int i = 0; i < q; i++) {
      scanf("%d %d", &cnt, &cost[i]);
      pack[i].clear();
      for(int j = 0; j < cnt; j++) {
	int num;
	scanf("%d", &num);
	pack[i].push_back(num);
      }
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    mi = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = i+1; j <= n; j++) {
	u[mi] = i;
	v[mi] = j;
	w[mi] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	idx[mi] = mi;
	mi++;
      }
    }
    sort(idx, idx+mi, cmp);
    init_union_find();
    ui = 0;
    cnt = 0;
    int ans = 0;
    for(int i = 0; i < mi && cnt < n - 1; i++) {
      int uu = find(u[idx[i]]);
      int vv = find(v[idx[i]]);
      if(uu != vv) {
	useful[ui++] = idx[i];
	cnt++;
	p[uu] = vv;
	ans += w[idx[i]];
      }
    }

    for(int i = 1; i < (1 << q); i++) {
      init_union_find();
      int cst = 0;
      cnt = 0;
      for(int j = 0; j < q; j++) {
	if(((1 << j) & i) != 0) {
	  cst += cost[j];
	  for(int k = 0; k < pack[j].size() - 1; k++) {
	    int uu = find(pack[j][k]);
	    int vv = find(pack[j][k+1]);
	    if(uu != vv) {
	      p[uu] = vv;
	      cnt++;
	    }
	  }
	}
      }
      for(int j = 0; j < ui && cnt < n - 1; j++) {
	int uu = find(u[useful[j]]);
	int vv = find(v[useful[j]]);
	if(uu != vv) {
	  p[uu] = vv;
	  cnt++;
	  cst += w[useful[j]];
	}
      }
      ans = min(ans, cst);
    }
    printf("%d\n", ans);
    if(tc)
      printf("\n");
  }
  return 0;
}
