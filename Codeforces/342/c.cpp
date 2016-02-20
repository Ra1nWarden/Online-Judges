#include <cstdio>

using namespace std;

const int maxn = 500;
int n, k;
int v[maxn+5][maxn+5];

int main() {
  scanf("%d%d", &n, &k);
  int number = n * n;
  for(int i = n - 1; i >= 0; i--) {
    for(int j = n - 1; j >= k - 1; j--) {
      v[i][j] = number--;
    }
  }
  number = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k - 1; j++) {
      v[i][j] = number++;
    }
  }
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += v[i][k-1];
  printf("%d\n", sum);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(j)
	printf(" ");
      printf("%d", v[i][j]);
    }
    printf("\n");
  }
  return 0;
}
