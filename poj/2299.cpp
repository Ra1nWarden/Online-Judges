#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500001

using namespace std;

struct Node {
  int val, pos;
  Node() {};
  Node(int x, int y) : val(x), pos(y) {};
  bool operator<(const Node& rhs) const {
    if(val != rhs.val)
      return val < rhs.val;
    return pos < rhs.pos;
  };
};

int A[MAXN];
Node S[MAXN];
int C[MAXN];
int n;
int maxa;


int lowbit(int x) {
  return x & (-x);
}

void add(int x, int d) {
  while(x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}

long long sum(int x) {
  long long res = 0;
  while(x > 0) {
    res += C[x];
    x -= lowbit(x);
  }
  return res;
}

int main() {
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      int x;
      scanf("%d", &A[i]);
      S[i] = Node(A[i], i);
    }
    sort(S, S+n);
    for(int i = 1; i <= n; i++) {
      A[S[i-1].pos] = i;
    }
    memset(C, 0, sizeof C);
    long long result = 0;
    for(int i = 0; i < n; i++) {
      result += (i - sum(A[i]));
      add(A[i], 1);
    }
    printf("%lld\n", result);
  }
  return 0;
}
