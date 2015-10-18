#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 50;
int a[2][maxn+5];
int b[maxn+1];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 2; i++) {
    if(i == 0) {
      a[i][0] = 0;
      for(int j = 1; j < n; j++) {
	scanf("%d", &a[i][j]);
	a[i][j] += a[i][j-1];
      }
    } else {
      a[i][n-1] = 0;
      for(int j = 0; j < n-1; j++) {
	scanf("%d", &a[i][j]);
      }
      for(int j = n-2; j >= 0; j--) {
	a[i][j] += a[i][j+1];
      }
    }
  }
  int mina = -1, minb = -1;
  for(int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    int sum = b[i] + a[0][i] + a[1][i];
    if(mina == -1) {
      mina = sum;
    } else if(minb == -1) {
      minb = sum;
      if(minb < mina) {
	swap(minb, mina);
      }
    } else if(sum < mina) {
      minb = mina;
      mina = sum;
    } else if(sum < minb) {
      minb = sum;
    }
  }
  printf("%d\n", mina + minb);
  return 0;
}
