#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
  char sex;
  int a;
  int diff;
  Node() {}
  Node(char s, int num, int d) : sex(s), a(num), diff(d) {}
  bool operator<(const Node& rhs) const {
    if(a != rhs.a)
      return a < rhs.a;
    else
      return diff > rhs.diff;
  }
};

const int maxn = 10000;
Node v[maxn+1];
int vi;

int main() {
  int n;
  scanf("%d\n", &n);
  vi = 0;
  for(int i = 0; i < n; i++) {
    char s;
    int start, end;
    scanf("%c %d %d\n", &s, &start, &end);
    v[vi++] = Node(s, start, 1);
    v[vi++] = Node(s, end, -1);
  }
  sort(v, v+vi);
  int ans = 0;
  int m = 0, f = 0;
  for(int i = 0; i < vi; i++) {
    if(v[i].sex == 'M') {
      m += v[i].diff;
    } else {
      f += v[i].diff;
    }
    ans = max(ans, min(m, f) * 2);
  }
  printf("%d\n", ans);
  return 0;
}
