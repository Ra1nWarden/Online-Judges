#include <cstdio>

using namespace std;

long long query(long long n, long long idx) {
  if(idx & 1) {
    return (idx + 1) >> 1;
  }
  long long new_idx = idx >> 1;
  if(n & 1) {
    new_idx--;
    if(new_idx == 0) {
      new_idx = n >> 1;
    }
  }
  return query(n >> 1, new_idx) + ((n + 1) >> 1);
}

int main() {
  long long n;
  int q;
  scanf("%I64d %d", &n, &q);
  long long idx;
  while(q--) {
    scanf("%I64d", &idx);
    printf("%I64d\n", query(n, idx));
  }
  return 0;
}
