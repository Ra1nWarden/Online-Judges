#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXA 1002

using namespace std;

struct Node {
  int x, y;
  Node() {};
  Node(int _x, int _y) : x(_x), y(_y) {};
  bool operator<(const Node& rhs) const {
    if(x != rhs.x)
      return x < rhs.x;
    return y < rhs.y;
  };
};

int C[MAXA];

int lowbit(int x) {
  return x & (-x);
}

long long sum(int x) {
  long long res = 0;
  while(x > 0) {
    res += C[x];
    x -= lowbit(x);
  }
  return res;
}

void add(int x, int d) {
  while(x < MAXA) {
    C[x] += d;
    x += lowbit(x);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    vector<Node> nodes;
    for(int i = 0; i < k; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      nodes.push_back(Node(x, y));
    }
    sort(nodes.begin(), nodes.end());
    memset(C, 0, sizeof C);
    long long result = 0;
    for(int i = 0; i < k; i++) {
      Node next = nodes[i];
      result += ((long long)i - sum(next.y));
      add(next.y, 1);
    }
    printf("Test case %d: %I64d\n", et, result);
  }
  return 0;
}

