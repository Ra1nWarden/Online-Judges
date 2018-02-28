#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int num;
    scanf("%d", &num);
    printf("%d\n", (num + 1) >> 1);
  }
  return 0;
}
