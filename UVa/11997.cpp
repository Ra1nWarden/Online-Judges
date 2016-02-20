#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxk = 750;
int v[maxk+5][maxk+5];
int k;
struct Node {
  int num, id;
  Node(int a, int b) : num(a), id(b) {}
  bool operator<(const Node& rhs) const {
    return num > rhs.num;
  }
};

void merge(int* a, int* b, int* c, int n) {
  priority_queue<Node> pq;
  for(int i = 0; i < k; i++)
    pq.push(Node(a[i] + b[0], 0));
  for(int i = 0; i < k; i++) {
    Node u = pq.top();
    pq.pop();
    c[i] = u.num;
    if(u.id + 1 < k)
      pq.push(Node(u.num - b[u.id] + b[u.id + 1], u.id + 1));
  }
}

int main() {
  while(scanf("%d", &k) != EOF) {
    for(int i = 0; i < k; i++) {
      for(int j = 0; j < k; j++) {
	scanf("%d", &v[i][j]);
      }
      sort(v[i], v[i]+k);
    }
    for(int i = 1; i < k; i++) {
      merge(v[0], v[i], v[0], k);
    }
    for(int i = 0; i < k; i++) {
      if(i)
	printf(" ");
      printf("%d", v[0][i]);
    }
    printf("\n");
  }
  return 0;
}
