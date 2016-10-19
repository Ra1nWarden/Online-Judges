#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int nb, mb;

int calc(int v, int b) {
  //printf("calc(%d, %d)=", v, b);
  int ans = 1;
  while(b--) {
    ans *= 7;
  }
  //printf("%d\n", v * ans);
  return v * ans;
}

int f(int i, int nn, int mm, int mask) {
  //printf("f(%d, %d, %d)\n", i, nn, mm);
  if(i == mb + nb)
    return 1;
  int ans = 0;
  if(i < mb) {
    for(int j = 0; j < 7; j++) {
      if((1 << j) & mask)
	continue;
      int add = calc(j, i);
      if(mm + add >= m)
	continue;
      ans += f(i+1, nn, mm + add, mask | (1 << j));
    }
  } else {
    i -= mb;
    for(int j = 0; j < 7; j++) {
      if((1 << j) & mask)
	continue;
      int add = calc(j, i);
      if(nn + add >= n)
	continue;
      ans += f(i+mb+1, nn + add, mm, mask | (1 << j));
    }
  }
  return ans;
}

int bits(int num) {
  int ans = 0;
  while(num) {
    num /= 7;
    ans++;
  }
  return max(1, ans);
}

int main() {
  scanf("%d%d", &n, &m);
  nb = bits(n-1);
  mb = bits(m-1);
  if(nb + mb > 7) {
    printf("0\n");
  } else {
    int mask = 0;
    printf("%d\n", f(0, 0, 0, mask));
  }
  return 0;
}
