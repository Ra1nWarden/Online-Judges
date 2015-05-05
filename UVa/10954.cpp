#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int x;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      pq.push(x);
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      sum += (a+b);
      pq.push(a+b);
    }
    printf("%d\n", sum);
  }
  return 0;
}
