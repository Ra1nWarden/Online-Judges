#include <cstdio>

using namespace std;

const int maxn = 1000;
bool v[maxn+1][maxn+1];
int n, m;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	int num;
	scanf("%d", &num);
	v[i][j] = num;
	if(v[i][j])
	  cnt++;
      }
    }
    bool a = cnt & 1;
    bool b = (m + n - 1) & 1;
    printf("%s\n", a == b ? "YES" : "NO");
  }
  return 0;
}
