#include <cstdio>
#include <algorithm>

using namespace std;

long long v[3];

int main() {
  scanf("%I64d %I64d %I64d", &v[0], &v[1], &v[2]);
  sort(v, v+3);
  printf("%I64d\n", min((v[0] + v[1] + v[2]) / 3, v[0] + v[1]));
  return 0;
}
