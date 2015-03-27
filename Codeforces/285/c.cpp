#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN (1 << 16) + 1

using namespace std;

int vertices[MAXN][2];

int main() {
  int n;
  scanf("%d", &n);
  queue<int> q;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    vertices[i][0] = a;
    vertices[i][1] = b;
    if(a == 1) {
      q.push(i);
    }
    sum += a;
  }
  printf("%d\n", sum / 2);
  while(!q.empty()) {
    int next = q.front();
    q.pop();
    if(vertices[next][0] == 1) {
      int connect = vertices[next][1];
      printf("%d %d\n", next, vertices[next][1]);
      vertices[connect][0]--;
      vertices[connect][1] ^= next;
      if(vertices[connect][0] == 1)
	q.push(connect);
    }
  }
  return 0;
}
