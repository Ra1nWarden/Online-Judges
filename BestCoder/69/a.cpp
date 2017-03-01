#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(c & 1) {
      printf("Impossible\n");
    } else {
      c >>= 1;
      int min_total = 2000;
      int min_a, min_b;
      for(int x = 0; x * a <= c; x++) {
	if((c - x * a) % b == 0) {
	  int y = (c - x * a) / b;
	  if(x + y < min_total) {
	    min_total = x + y;
	    min_a = x, min_b = y;
	  }
	}
      }
      if(min_total == 2000) {
	printf("Impossible\n");
      } else {
	printf("%d %d\n", min_a * 2, min_b * 2);
      }
    }
  }
  return 0;
}
