#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MAXN 15001
#define MAXA 1002

using namespace std;

struct Node {
  int x, y, z;
  Node() {};
  Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
  bool operator<(const Node& rhs) const {
    if(x != rhs.x)
      return x < rhs.x;
    if(y != rhs.y)
      return y < rhs.y;
    return z < rhs.z;
  };
};

int n;
Node nodes[MAXN];
int C[MAXA][MAXA];
int result[MAXN];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x, int y) {
  int res = 0;
  for(int i = x; i > 0; i -= lowbit(i)) {
    for(int j = y; j > 0; j -= lowbit(j)) {
      res += C[i][j];
    }
  }
  return res;
}

void add(int x, int y, int d) {
  for(int i = x; i < MAXA; i += lowbit(i)) {
    for(int j = y; j < MAXA; j += lowbit(j)) {
      C[i][j] += d;
    }
  }
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++) {
      int x, y, z;
      scanf("%d %d %d", &nodes[i].x, &nodes[i].y, &nodes[i].z);
    }
    sort(nodes + 1, nodes + n + 1);
    //cout << "here 1" << endl;
    memset(C, 0, sizeof C);
    memset(result, 0, sizeof result);
    //cout << "here 2" << endl;
    for(int i = 1; i <= n; i++) {
      Node next = nodes[i];
      result[sum(next.y+1, next.z+1)]++;
      add(next.y+1, next.z+1, 1);
    }
    //cout << "here 3" << endl;
    for(int i = 0; i < n; i++) {
      if(i != 0)
	printf(" ");
      printf("%d", result[i]);
    }
    printf("\n");
  }
  return 0;
}
