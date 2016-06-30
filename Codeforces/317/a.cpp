#include <cstdio>
#include <algorithm>

using namespace std;

int choose(int i) {
  return i % 3 == 0 ? 1 : 3;
}

int calc(int a, int b, int c, int aa, int bb, int cc) {
  printf("%d, %d, %d => %d, %d, %d\n", a, b, c, aa, bb, cc);
  int v1[] = {a, b, c};
  int v2[] = {aa, bb, cc};
  int ans = 1;
  for(int i = 0; i < 3; i++) {
    ans *= (lower_bound(v1, v1+3, v2[i]))
  }
  return ans;
}

int main() {
  int a, b, c, l;
  scanf("%d%d%d%d", &a, &b, &c, &l);
  if(a > b)
    swap(a, b);
  if(b > c)
    swap(b, c);
  if(a > b)
    swap(a, b);
  int ans = 0;
  for(int i = 0; i <= l; i++) {
    if(a+b+l-i <= c+i)
      break;
    int cc = c + i;
    // j == aa + bb;
    for(int j = cc+1; j <= min(cc * 2, a+b+l-i); j++) {
      for(int bb = (j + 1) / 2; bb <= j - a; bb++) {
	int aa = j - bb;
	ans += calc(a, b, c, aa, bb, cc);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
