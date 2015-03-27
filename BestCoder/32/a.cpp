#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  int f, s, i;
  Node() {};
  Node(int a, int b, int c) : f(a), s(b), i(c) {};
};

bool _cmp(const Node& a, const Node& b) {
  if(a.f - a.s != b.f - b.s) {
    return a.f - a.s > b.f - b.s;
  }
  if(a.s != b.s) {
    return a.s < b.s;
  }
  return a.i < b.i;
}

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    vector<Node> v(n);
    for(int i = 0; i < n; i++) {
      int first, second;
      scanf("%d %d", &first, &second);
      v[i] = Node(first, second, i);
    }
    sort(v.begin(), v.end(), _cmp);
    for(int i = 0; i < n; i++) {
      if(i != 0)
	printf(" ");
      printf("%d", v[i].i);
    }
    printf("\n");
  }
  return 0;
}
