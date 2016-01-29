#include <cstdio>

using namespace std;

const int maxn = 100;
bool v[maxn+1];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int f;
    scanf("%d", &f);
    v[i] = f;
  }
  int start = -1, end = -1;
  for(int i = 0; i < n; i++) {
    if(v[i]) {
      start = i;
      break;
    }
  }
  if(start == -1) {
    printf("0\n");
    return 0;
  }
  for(int i = n - 1; i > -1; i--) {
    if(v[i]) {
      end = i;
      break;
    }
  }
  if(start == end) {
    printf("1\n");
    return 0;
  }
  long long ans = 1;
  long long base = 1;
  for(int i = start + 1; i < end; i++) {
    if(v[i]) {
      ans *= base;
      base = 1;
    } else {
      base++;
    }
  }
  ans *= base;
  printf("%I64d\n", ans);
  return 0;
}
