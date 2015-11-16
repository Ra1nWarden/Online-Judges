#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    sum += num;
  }
  int r = sum % n;
  printf("%d\n", r == 0 ? n : n - 1);
  return 0;
}
