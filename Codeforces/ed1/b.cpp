#include <cstdio>

using namespace std;

const int maxl = 10000;
char str[maxl+5];
char buff[maxl+5];

void transform(int l, int r, int k) {
  k %= (r - l + 1);
  for(int i = 0; i <= r - l; i++) {
    buff[(i+k)%(r-l+1)] = str[l + i]; 
  }
  int idx = 0;
  for(int i = l; i <= r; i++) {
    str[i] = buff[idx++];
  }
}

int main() {
  scanf("%s\n", str);
  int m;
  scanf("%d", &m);
  while(m--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;
    r--;
    transform(l, r, k);
  }
  printf("%s\n", str);
  return 0;
}
