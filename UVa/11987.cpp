#include <cstdio>

using namespace std;

const int maxn = 200000;
int n, m;
int f[maxn+5], cnt[maxn+5], sum[maxn+5];
int memo[maxn+5];
int idx;

int find_set(int a) {
  return f[a] == a ? a : f[a] = find_set(f[a]);
}

void union_set(int a, int b) {
  //printf("union %d %d\n", a, b);
  int fa = find_set(memo[a]);
  int fb = find_set(memo[b]);
  //printf("fa %d fb %d\n", fa, fb);
  //printf("before merge cnt[%d]=%d sum[%d]=%d\n", fa, cnt[fa], fa, sum[fa]);
  //printf("before merge cnt[%d]=%d sum[%d]=%d\n", fb, cnt[fb], fb, sum[fb]);
  if(fa != fb) {
    f[fa] = fb;
    cnt[fb] += cnt[fa];
    sum[fb] += sum[fa];
  }
  //printf("parent is %d cnt %d sum is %d\n", fb, cnt[fb], sum[fb]);
}

void init(int a) {
  memo[a] = idx;
  f[idx] = idx;
  cnt[idx] = 1;
  sum[idx] = a;
  idx++;
}

int main() {
  while(~scanf("%d%d", &n, &m)) {
    for(int i = 1; i <= n; i++) {
      f[i] = i;
      cnt[i] = 1;
      sum[i] = i;
      memo[i] = i;
    }
    idx = n+1;
    while(m--) {
      int op;
      scanf("%d", &op);
      if(op == 1) {
	int p, q;
	scanf("%d%d", &p, &q);
	union_set(p, q);
      } else if(op == 2) {
	int p, q;
	scanf("%d%d", &p, &q);
	int fp = find_set(memo[p]);
	int fq = find_set(memo[q]);
	if(fp != fq) {
	  //printf("removing %d cnt=%d sum=%d\n", fp, cnt[fp], sum[fp]);
	  cnt[fp]--;
	  sum[fp] -= p;
	  init(p);
	  union_set(p, q);
	}
      } else if(op == 3) {
	int p;
	scanf("%d", &p);
	int fp = find_set(memo[p]);
	//printf("find set %d is %d\n", p, fp);
	printf("%d %d\n", cnt[fp], sum[fp]);
      }
    }
  }
  return 0;
}
