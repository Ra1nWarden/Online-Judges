#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int maxn = 500;
int v[maxn+5];
int vi;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  scanf("%d", &n);
  map<int, int> cm;
  priority_queue<int> pq;
  for(int i = 0; i < n * n; i++) {
    int num;
    scanf("%d", &num);
    cm[num]++;
    pq.push(num);
  }
  vi = 0;
  while(vi < n) {
    while(!pq.empty()) {
      int next = pq.top();
      pq.pop();
      if(cm.count(next) && cm[next]) {
	v[vi] = next;
	for(int i = 0; i < vi; i++) {
	  cm[gcd(v[i], next)] -= 2;
	}
	cm[next]--;
	vi++;
	break;
      }
    }
  }
  for(int i = 0; i < vi; i++) {
    if(i > 0) {
      printf(" ");
    }
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
