#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int a, b, s;
  scanf("%d %d %d", &a, &b, &s);
  int sum = abs(a) + abs(b);
  if(s < sum)
    printf("No\n");
  else if((s - sum) % 2 == 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
