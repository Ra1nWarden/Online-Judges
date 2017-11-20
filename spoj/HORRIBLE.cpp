#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000000;

long long BIT[MAXN+5][2];
int n, c;

int lowbit(int x) {
  return x & (-x);
}

void add(int pos, long long x, int f) {
  while(pos <= n) {
    BIT[pos][f] += x;
    pos += lowbit(pos);
  }
}

long long query(int pos, int f) {
  long long ans = 0;
  while(pos) {
    ans += BIT[pos][f];
    pos -= lowbit(pos);
  }
  return ans;
}

long long query(int pos) {
  return (pos + 1) * 1LL * query(pos, 0) - query(pos, 1);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(BIT, 0, sizeof BIT);
    scanf("%d%d", &n, &c);
    while(c--) {
      int cmd, p, q;
      long long v;
      scanf("%d", &cmd);
      if(cmd == 0) {
	scanf("%d%d%lld", &p, &q, &v);
	add(p, v, 0);
	add(q + 1, -v, 0);
	add(p, v * p, 1);
	add(q + 1, -v * (q + 1), 1);
      } else {
	scanf("%d%d", &p, &q);
	printf("%lld\n", query(q) - query(p - 1));
      }
    }
  }
  return 0;
}
