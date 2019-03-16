#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    int ans = min(a, b) * 2;
    if(a > b)
      ans++;
    switch(ans % 4) {
    case 0:
      printf("R\n");
      break;
    case 1:
      printf("D\n");
      break;
    case 2:
      printf("L\n");
      break;
    case 3:
      printf("U\n");
      break;
    }
  }
  return 0;
}
