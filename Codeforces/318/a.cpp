#include <cstdio>
#include <vector>
#define MAXN 100005

using namespace std;

int n;

bool possible(int a, int b) {
  while(a % 2 == 0)
    a /= 2;
  while(a % 3 == 0)
    a /= 3;
  while(b % 2 == 0)
    b /= 2;
  while(b % 3 == 0)
    b /= 3;
  return a == b;
}

int main() {
  scanf("%d", &n);
  int prev;
  scanf("%d", &prev);
  for(int i = 1; i < n; i++) {
    int next;
    scanf("%d", &next);
    if(!possible(prev, next)) {
      printf("No\n");
      return 0;
    }
    prev = next;
  }
  printf("Yes\n");
  return 0;
}
