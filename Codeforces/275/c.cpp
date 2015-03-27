#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

bool a[MAXN];
int v[MAXN];
int n, k;

int main() {
  scanf("%d %d", &n, &k);
  memset(a, true, sizeof a);
  int index = 0;
  int num = 1;
  bool inc = true;
  int diff = k;
  while(index < n) {
    v[index++] = num;
    a[num] = false;
    if(inc)
      num += diff;
    else
      num -= diff;
    if(diff > 1) {
      diff--;
      inc = !inc;
    }
    if(!a[num]) {
      num = 1+k+1;
      inc = true;
    }
  }
  
  for(int i = 0; i < index; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
