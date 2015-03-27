#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 610
#define START 305

using namespace std;

int m, t, r;
int led[MAXN];
bool ling[MAXN];
int res = 0;

// light n more candles for x
bool light(int x, int n) {
  //printf("called light x= %d n = %d\n", x, n);
  while(n > 0) {
    bool success = false;
    for(int i = START + x - 1; i >= START + x  - t; i--) {
      if(!ling[i]) {
	ling[i] = true;
	res++;
	for(int j = i + 1; j <= min(i + t, MAXN - 1); j++) {
	  //printf("incrementing %d\n", j);
	  led[j]++;
	}
	n--;
	success = true;
	break;
      }
    }
    if(!success) {
      //printf("failed when n = %d\n", n);
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d %d %d", &m, &t, &r);
  memset(led, 0, sizeof led);
  memset(ling, false, sizeof ling);
  bool success = true;
  for(int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    if(led[START + x] >= r)
      continue;
    int needed = r - led[START + x];
    if(!light(x, needed)) {
      success = false;
      break;
    }
  }
  if(success) {
    printf("%d\n", res);
  }
  else
    printf("-1\n");
  return 0;
}
