#include <cstdio>

using namespace std;

const int maxn = 512;
bool mat[maxn+1][maxn+1];

void solve(int n) {
  if(n == 0) {
    mat[0][0] = true;
  } else {
    solve(n - 1);
    for(int i = 0; i < (1 << (n - 1)); i++) {
      for(int j = (1 << (n - 1)); j < (1 << n); j++) {
	mat[i][j] = mat[i][j - (1 << (n - 1))];
      }
    }
    for(int i = 1 << (n - 1); i < (1 << n); i++) {
      for(int j = 0; j < (1 << (n - 1)); j++) {
	mat[i][j] = mat[i - (1 << (n - 1))][j];
      }
    }
    for(int i = (1 << (n - 1)); i < (1 << n); i++) {
      for(int j = (1 << (n - 1)); j < (1 << n); j++) {
	mat[i][j] = !mat[i - (1 << (n - 1))][j - (1 << (n - 1))];
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  solve(n);
  for(int i = 0; i < (1 << n); i++) {
    for(int j = 0; j < (1 << n); j++) {
      if(mat[i][j])
	printf("+");
      else
	printf("*");
    }
    printf("\n");
  }
}
