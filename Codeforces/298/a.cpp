#include <cstdio>
#define MAXN 5005

using namespace std;

int output[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  if(n == 2) {
    printf("1\n1\n");
  }
  else if(n == 3) {
    printf("2\n");
    printf("1 3\n");
  } else if(n == 4) {
    printf("4\n");
    printf("2 4 1 3\n");
  } else {
    int num = 1;
    for(int i = 1; i <= n; i+=2) {
      output[i] = num++;
    }
    for(int i = 2; i <= n; i+=2) {
      output[i] = num++;
    }
    printf("%d\n", n);
    for(int i = 1; i <= n; i++) {
      if(i != 1)
	printf(" ");
      printf("%d", output[i]);
    }
    printf("\n");
  }
  return 0;
}
