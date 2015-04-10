#include <cstdio>
#include <set>
#include <cmath>
#define MAXN 2005

using namespace std;

int mat[MAXN][MAXN];
int n;

int main() {
  scanf("%d", &n);
  for(int i =0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
  bool ok = true;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      if(i == j) {
	if(mat[i][j] != 0) {
	  printf("NO\n");
	  return 0;
	}
      } else {
	if(mat[i][j] != mat[j][i]) {
	  printf("NO\n");
	  return 0;
	}
	if(mat[i][j] == 0) {
	  printf("NO\n");
	  return 0;
	}
      }
    }
  }

  set<int> sum;

  for(int i = 0; i < n; i++)
    sum.insert(mat[0][i] * 2);

  // assume 0 is the root
  for(int i = 1; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      int d = mat[0][i] + mat[0][j] - mat[i][j];
      if(sum.count(d) == 0) {
	if(mat[i][j] != abs(mat[0][i] - mat[0][j])) {
	  printf("NO\n");
	  return 0;
	}
      }
    }
  }
  printf("YES\n");
  return 0;
}
