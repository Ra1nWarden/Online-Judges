#include <cstdio>
#include <cstring>

using namespace std;

int n, k, a, b, c, d;
const int maxn = 1000;
bool visited[maxn+5];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if(k <= n || n < 5)
    printf("-1\n");
  else if(n == 5) {
    int e = -1;
    for(int i = 1; i <= 5; i++) {
      if(i == a || b == i || c == i || d == i)
	continue;
      else {
	e = i;
	break;
      }
    }
    printf("%d %d %d %d %d\n", a, d, e, c, b);
    printf("%d %d %d %d %d\n", c, b, e, a, d);
  } else {
    int e = -1, f = -1;
    for(int i = 1; i <= n; i++) {
      if(i != a && i != b && i != c && i != d) {
	if(e == -1) {
	  e = i;
	} else if(f == -1) {
	  f = i;
	  break;
	}
      }
    }
    memset(visited, false, sizeof visited);
    int cur = a;
    for(int i = 0; i < n; i++) {
      if(i)
	printf(" ");
      printf("%d", cur);
      visited[cur] = true;
      if(i == n - 2) {
	cur = b;
      } else if(cur == a) {
	cur = e;
      } else if(cur == e) {
	cur = c;
      } else if(cur == c) {
	cur = f;
      } else if(cur == f) {
	cur = d;
      } else if(cur == d) {
	cur = b == 1 ? 2 : 1;
      }
      if(cur != b) {
	while(cur <= n && (visited[cur] || cur == b))
	  cur++;
      }
    }
    printf("\n");
    memset(visited, false, sizeof visited);
    cur = c;
    for(int i = 0; i < n; i++) {
      if(i)
	printf(" ");
      printf("%d", cur);
      visited[cur] = true;
      if(i == n - 2) {
	cur = d;
      } else if(cur == c) {
	cur = f;
      } else if(cur == f) {
	cur = a;
      } else if(cur == a) {
	cur = e;
      } else if(cur == e) {
	cur = b;
      } else if(cur == b) {
	cur = d == n ? n - 1 : n;
      }
      if(cur != d) {
	while(cur > 0 && (visited[cur] || cur == d))
	  cur--;
      }
    }
    printf("\n");
  }
  return 0;
}
