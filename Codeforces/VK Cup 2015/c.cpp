#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 205

using namespace std;

int f[MAXN];
int n, bi;
bool counted[MAXN];
int buffer[MAXN];

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a%b);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
  }
  memset(counted, false, sizeof counted);
  long long ans = 1;
  int minVal = 0;
  for(int i = 1; i <= n; i++) {
    if(counted[i])
      continue;
    int num = i;
    bi = 0;
    buffer[bi++] = num;
    bool lcm_mode = true;
    counted[num] = true;
    int length = 0;
    while(true) {
      if(f[num] == f[f[num]]) {
	minVal = max(minVal, bi);
	lcm_mode = false;
	break;
      }
      counted[num] = true;
      num = f[num];    
      for(int j = 0; j < bi; j++) {
	if(buffer[j] == num) {
	  length = bi - j;
	  minVal = max(minVal, j);
	  break;
	}
      }
      //printf("inserting %d at %d\n", num, bi);
      buffer[bi++] = num;
      if(length != 0)
	break;
    }
    if(lcm_mode)
      ans = lcm(ans, (long long)length);
  }
  int mult = 1;
  //printf("ans is %I64d minVal is %d\n", ans, minVal);
  while(ans * mult < minVal)
    mult++;
  printf("%I64d\n", ans * mult);
  return 0;
}
