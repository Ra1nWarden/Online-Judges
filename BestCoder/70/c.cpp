#include <cstdio>
#include <map>

using namespace std;

const int maxn = 500;
const int mod = 5201314;
char v[maxn+5][maxn+5];
int n;
typedef pair<int, int> Coord;
typedef pair<Coord, Coord> Query;
map<Query, int> memo;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

inline Query make(int a, int b, int c, int d) {
  return make_pair(make_pair(a, b), make_pair(c, d));
}

int f(int a, int b, int c, int d) {
  if(a == c && b == d)
    return 1;
  Query q = make(a, b, c, d);
  if(memo.count(q))
    return memo[q];
  if(v[a][b] != v[c][d])
    return 0;
  int ans = 0;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      int aa = a + dx[i];
      int bb = b + dy[i];
      int cc = c - dx[j];
      int dd = d - dy[j];
      if(aa > cc)
	continue;
      if(bb > dd)
	continue;
      if(v[aa][bb] == v[cc][dd])
	ans = (ans + f(aa, bb, cc, dd)) % mod;
    }
  }
  return memo[q] = ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%s\n", v[i]);
    printf("%d\n", f(0, 0, n-1, n-1));
  }
  return 0;
}
