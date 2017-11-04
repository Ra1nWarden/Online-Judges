#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  int tc, num;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &num);
    int n = num;
    for(int i = 2; i <= sqrt(n + 0.5); i++) {
      if(n % i == 0) {
	while(n % i == 0) {
	  n /= i;
	}
	num = num / i * (i - 1);
      }
    }
    if(n > 1)
      num = num / n * (n - 1);
    printf("%d\n", num);
  }
  return 0;
}
