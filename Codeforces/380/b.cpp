#include <cstdio>

using namespace std;

const int maxn = 1000;
int n, m;
int v[maxn+5][maxn+5];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    bool ok = false;
    for(int j = 0; j < m; j++) {
      if(v[i][j]) {
	ok = true;
      } else if(ok) {
	ans++;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    bool ok = false;
    for(int j = m-1; j >= 0; j--) {
      if(v[i][j]) {
	ok = true;
      } else if(ok) {
	ans++;
      }
    }
  }
  for(int j = 0; j < m; j++) {
    bool ok = false;
    for(int i = 0; i < n; i++) {
      if(v[i][j]) {
	ok = true;
      } else if(ok) {
	ans++;
      }
    }
  }
  for(int j = 0; j < m; j++) {
    bool ok = false;
    for(int i = n - 1; i >= 0; i--) {
      if(v[i][j]) {
	ok = true;
      } else if(ok) {
	ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
