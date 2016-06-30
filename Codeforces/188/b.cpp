#include <cstring>
#include <cstdio>

using namespace std;

const int maxl = 1e6;

char str[maxl+5];

bool heavy(int j) {
  char heavy_str[] = "heavy";
  for(int i = 0; i < 5; i++) {
    if(str[j+i] != heavy_str[i])
      return false;
  }
  return true;
}

bool metal(int j) {
  char metal_str[] = "metal";
  for(int i = 0; i < 5; i++) {
    if(str[j+i] != metal_str[i])
      return false;
  }
  return true;
}

int main() {
  scanf("%s", str);
  int n = strlen(str);
  long long ans = 0;
  long long cnt = 0;
  for(int i = 0; i <= n - 5; i++) {
    if(heavy(i))
      cnt++;
    if(metal(i)) {
      ans += cnt;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
