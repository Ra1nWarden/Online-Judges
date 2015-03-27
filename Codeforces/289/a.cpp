#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int m[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0 || j == 0)
	m[i][j] = 1;
      else {
	int entry = 0;
	if(i - 1 > -1) {
	  entry += m[i-1][j];
	}
	if(j - 1 > -1)
	  entry += m[i][j-1];
	m[i][j] = entry;
      }
    }
  }
  printf("%d\n", m[n-1][n-1]);
}
