#include <cstdio>
#include <map>

using namespace std;

map<long long, long long> m;

int depth(long long num) {
  int ans = 0;
  while(num) {
    num >>= 1;
    ans++;
  }
  return ans;
}

void inc(long long k, long long v) {
  if(m.count(k)) {
    m[k] = m[k] + v;
  } else {
    m[k] = v;
  }
}

int main() {
  int q;
  scanf("%d", &q);
  while(q--) {
    int op;
    scanf("%d", &op);
    if(op == 1) {
      long long v, u;
      int w;
      scanf("%I64d %I64d %d", &v, &u, &w);
      while(v != u) {
	if(depth(v) < depth(u)) {
	  inc(u, w);
	  u >>= 1;
	} else if(depth(v) > depth(u)) {
	  inc(v, w);
	  v >>= 1;
	} else {
	  inc(v, w);
	  inc(u, w);
	  v >>= 1;
	  u >>= 1;
	}
      }
    } else {
      long long v, u;
      scanf("%I64d %I64d", &v, &u);
      long long ans = 0;
      while(v != u) {
	if(depth(v) < depth(u)) {
	  ans += m[u];
	  u >>= 1;
	} else if(depth(v) > depth(u)) {
	  ans += m[v];
	  v >>= 1;
	} else {
	  ans += m[v];
	  ans += m[u];
	  v >>= 1;
	  u >>= 1;
	}
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
