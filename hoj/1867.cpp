#include <cstdio>
#include <cstring>

using namespace std;

bool prime[10000000];
int C[1000000];
int num[1000000];
int A[1000000];
int c, n, m;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= c) {
    C[x] += d;
    x += lowbit(x);
  }
}

int main() {
  memset(prime, true, sizeof prime);
  prime[0] = false;
  prime[1] = false;
  for(int i = 2; i < 10000000; i++) {
    if(prime[i]) {
      for(int j = i + i; j < 10000000; j += i)
	prime[j] = false;
    }
  }
  int tc = 1;
  while(scanf("%d %d %d", &c, &n, &m) && (c || n || m)) {
    bool mprime = prime[m];
    memset(num, 0, sizeof num);
    memset(A, 0, sizeof A);
    memset(C, 0, sizeof C);
    for(int i = 1; i <= c; i++) {
      num[i] = m;
      if(mprime)
	add(i, 1);
    }
    printf("CASE #%d:\n", tc++);
    for(int i = 0; i < n; i++) {
      int q, x, y;
      scanf("%d %d %d", &q, &x, &y);
      if(q == 0) {
	bool orig = prime[num[x]];
	num[x] += y;
	bool newprime = prime[num[x]];
	if(!orig && newprime) {
	  add(x, 1);
	} else if(orig && !newprime) {
	  add(x, -1);
	}
      } else if (q == 1) {
	printf("%d\n", sum(y) - sum(x - 1));
      }
    }
    printf("\n");
  }
  
  return 0;
}
