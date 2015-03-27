#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100005

using namespace std;

int n, p;
char str[MAXN];

int main() {
  scanf("%d %d\n", &n, &p);
  scanf("%s\n", str);
  if(p > (n / 2))
    p = n - p + 1;
  reverse(str, str+n);
  int l = -1;
  for(int i = 0; i < p; i++) {
    if(str[i] != str[n - 1 - i]) {
      l = i;
      break;
    }
  }
  int r = -1;
  for(int i = n/2 - 1; i >= p; i--) {
    if(str[i] != str[n - 1 - i]) {
      r = i;
      break;
    }
  }
  int lres = 0;
  if(l != -1) {
    int pos = p - 1;
    while(pos >= l) {
      if(str[pos] != str[n - 1 - pos]) {
	int presses = abs(str[pos] - str[n - 1 - pos]);
	lres += min(presses, 26 - presses);
      }
      pos--;
      if(pos >= l)
	lres++;
    }
  }
  int rres = 0;
  if(r != -1) {
    rres = 1;
    int pos = p;
    while(pos <= r) {
      if(str[pos] != str[n - 1 - pos]) {
	int presses = abs(str[pos] - str[n - 1 - pos]);
	rres += min(presses, 26 - presses);
      }
      pos++;
      if(pos <= r)
	rres++;
    }
  }
  //printf("l=%d r=%d lres=%d rres=%d\n", l, r, lres, rres);
  if(l == -1)
    printf("%d\n", rres);
  else if(r == -1)
    printf("%d\n", lres);
  else
    printf("%d\n", min(lres + (p - 1 - l) + rres, rres + (r - p + 1) + lres));
  return 0;
}
