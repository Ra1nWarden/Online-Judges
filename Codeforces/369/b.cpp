#include <cstdio>

using namespace std;

const int maxn = 500;
int n;
long long mat[maxn+5][maxn+5];

int main() {
  scanf("%d", &n);
  int a, b;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%I64d", &mat[i][j]);
      if(mat[i][j] == 0) {
	a = i;
	b = j;
      }
    }
  }
  if(n == 1) {
    printf("1\n");
    return 0;
  }
  long long sum = 0;
  int i = 0;
  if(a == 0) {
    i = 1;
  }
  for(int j = 0; j < n; j++) {
    sum += mat[i][j];
  }
  long long rest = 0;
  for(int j = 0; j < n; j++) {
    rest += mat[a][j];
  }
  long long ans = sum - rest;
  mat[a][b] = ans;
  bool ok = true;
  for(int i = 0; i < n; i++) {
    long long r = 0;
    for(int j = 0; j < n; j++) {
      r += mat[i][j];
    }
    if(r != sum) {
      ok = false;
      break;
    }
  }
  if(!ok) {
    printf("-1\n");
    return 0;
  }
  for(int j = 0; j < n; j++) {
    long long r = 0;
    for(int i = 0; i < n; i++) {
      r += mat[i][j];
    }
    if(r != sum) {
      ok = false;
      break;
    }
  }
  if(!ok) {
    printf("-1\n");
    return 0;
  }
  long long c = 0;
  for(int i = 0; i < n; i++) {
    c += mat[i][i];
  }
  if(c != sum) {
    printf("-1\n");				
    return 0;
  }
  c = 0;
  for(int i = 1; i <= n; i++) {
    c += mat[i-1][n-i];
  }
  if(c != sum || ans <= 0) {
    printf("-1\n");
  } else {
    printf("%I64d\n", ans);
  }
  return 0;
}
