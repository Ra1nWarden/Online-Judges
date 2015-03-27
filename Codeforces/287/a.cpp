#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
  int a, i;
  Node() {};
  Node(int _a, int _i) : a(_a), i(_i) {};
  bool operator<(const Node& b) const {
    return a < b.a;
  };
};

Node a[105];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i].a);
    a[i].i = i+1;
  }
  sort(a, a+n);
  vector<int> v;
  for(int i = 0; i < n; i++) {
    if(k < a[i].a)
      break;
    if(k > 0 && k >= a[i].a) {
      k -= a[i].a;
      v.push_back(a[i].i);
    }
  }
  printf("%lu\n", v.size());
  for(int i = 0; i < v.size(); i++) {
    if(i != 0)
      printf(" ");
    printf("%d", v[i]);
  }
  if(v.size() != 0)
    printf("\n");
  return 0;
}
