#include <cstdio>

using namespace std;

long long sg(long long x) {
  return x % 2 == 0 ? x / 2 : sg(x / 2);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int n;
    scanf("%d", &n);
    long long nim = 0;
    for(int i = 0; i < n; i++) {
      long long num;
      scanf("%lld", &num);
      nim ^= sg(num);
    }
    if(nim) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
