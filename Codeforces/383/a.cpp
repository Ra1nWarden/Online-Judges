#include <cstdio>

using namespace std;

int v[] = {8, 4, 2, 6};

int main() {
  int n;
  scanf("%d", &n);
  if(n == 0)
    printf("1\n");
  else
    printf("%d\n", v[(n - 1) % 4]);
  return 0;
}
