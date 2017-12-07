#include <cstdio>
#include <cmath>

using namespace std;

bool test(long long num) {
  for(long long i = 0; i * i <= num / 2; i++) {
    long long jj = num - i * i;
    long long j = (long long) sqrt(jj);
    if(j * j == jj)
      return true;
  }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long num;
    scanf("%lld", &num);
    printf("%s\n", test(num) ? "Yes" : "No");
  }
  return 0;
}
