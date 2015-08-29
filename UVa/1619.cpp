#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 100010

using namespace std;

int n;
long long v[MAXN];
long long sum[MAXN];
int l[MAXN];
int r[MAXN];
typedef pair<long long, int> Node;

int main() {
  scanf("%d", &n);
  while(true) {
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%lld", &v[i]);
      sum[i] = sum[i-1] + v[i];
    }
    int s, t;
    memset(l, 0, sizeof l);
    for(int i = 1; i <= n; i++)
      r[i] = n+1;
    stack<Node> st;
    for(int i = 1; i <= n; i++) {
      long long num = v[i];
      while(!st.empty()) {
	Node u = st.top();
	if(u.first >= num) {
	  r[u.second] = i;
	  st.pop();
	} else {
	  l[i] = u.second;
	  break;
	}
      }
      st.push(make_pair(num, i));
    }

    long long ans = -1;
    for(int i = 1; i <= n; i++) {
      long long prod = v[i] * (sum[r[i] - 1] - sum[l[i]]);
      if(ans == -1 || prod > ans) {
	ans = prod;
	s = l[i] + 1;
	t = r[i] - 1;
      }
    }
    printf("%lld\n%d %d\n", ans, s, t);
    if(scanf("%d", &n) != EOF) {
      printf("\n");
    } else {
      break;
    }
  }
  return 0;
}
